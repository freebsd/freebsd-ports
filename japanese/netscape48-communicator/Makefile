# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.08
# Date created:		13 Mar 1998
# Whom:			sada@FreeBSD.ORG
#
# $Id: Makefile,v 1.14 1998/12/29 21:53:19 sada Exp $
#

DISTNAME=	ja-netscape-${BROWSER}-${BROWSER_VERSION}
CATEGORIES=	japanese www
MASTER_SITES=	http://www.bres.tsukuba.ac.jp/~yohta/netscape/ \
		${PORTKIT_SITES}
DISTFILES=	${JAPANIZE_KIT} ${PORTKIT}

MAINTAINER=	sada@FreeBSD.ORG

# ?= for ports that include this Makefile
RUN_DEPENDS?=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape4-${BROWSER} \
		${FONT_DEPEND}

MAN1=		ja-netscape.1
MANLANG=	ja
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL
PLIST=		${.CURDIR}/pkg/PLIST
PLIST_SUB=	NSUBDIR=${NSUBDIR} LANG=${LANG}
WRKSRC=		${WRKDIR}/netscape-ja_euc

BROWSER?=	communicator
BROWSER_CMD?=	ja-${BROWSER}-4
BROWSER_VERSION?= 4.08
FONT_DEPEND=	${PKG_DBDIR}/ja-netscape-fonts-1.0:${PORTSDIR}/japanese/netscape-fonts
JAPANIZE_KIT?=	communicator-ja-euc-v407-export.generic-generic-generic.tar.gz
LANG=		ja_JP.EUC
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER@;${BROWSER}-${BROWSER_VERSION};g" \
			-e "s;@LANG@;${LANG};g"
MANDIR=		${MANPREFIX}/man/${MANLANG}
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR?=	lib/netscape
PORTKIT=	ja-netscape-portkit.1998.1230.tar.gz
PORTKIT_DIR=	${WRKDIR}/portkit
PORTKIT_SITES=	http://WWW.JP.FreeBSD.ORG/~sada/distfiles/ \
		http://WWW.FreeBSD.ORG/~sada/distfiles/

.SILENT:

do-configure:
	${MAKESCRIPT} ${PORTKIT_DIR}/start.sh.in >${WRKDIR}/start.sh
	${MAKESCRIPT} ${PORTKIT_DIR}/Netscape.${BROWSER}-${BROWSER_VERSION} \
		>${WRKDIR}/Netscape
	${MAKESCRIPT} ${MASTERDIR}/files/INSTALL >${PKGINSTALL}
	${CP} ${PORTKIT_DIR}/about.${BROWSER}-${BROWSER_VERSION} ${WRKDIR}/about
	${CP} ${WRKDIR}/about ${WRKDIR}/splash

do-install:
	${INSTALL_DATA} ${PORTKIT_DIR}/preferences.js ${NDIR}
	${MKDIR} ${NDIR}/locale
	${LN} -sf /usr/share/locale/en_US.ISO_8859-1 ${NDIR}/locale/${LANG}
	${MKDIR} ${NDIR}/${LANG}
.for f in mail.msg netscape.cfg plugins
	${INSTALL_DATA} ${WRKSRC}/$f ${NDIR}/${LANG}/
.endfor
.for f in Netscape about splash
	${INSTALL_DATA} ${WRKDIR}/$f ${NDIR}/${LANG}/
.endfor
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/nethelp-v406.nif \
		${EXTRACT_AFTER_ARGS} -C ${NDIR}/${LANG}
	${INSTALL_SCRIPT} ${WRKDIR}/start.sh ${PREFIX}/bin/${BROWSER_CMD}
	${LN} -sf ${BROWSER_CMD} ${PREFIX}/bin/netscape
	${MKDIR} ${MANDIR}/man1
	${INSTALL_MAN} ${PORTKIT_DIR}/${MAN1} ${MANDIR}/man1

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
