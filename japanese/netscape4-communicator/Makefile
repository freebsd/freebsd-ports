# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.07
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id: Makefile,v 1.9 1998/11/24 15:09:09 sada Exp $
#

DISTNAME=	ja-netscape-${BROWSER}
CATEGORIES=	japanese www
MASTER_SITES=	http://www.bres.tsukuba.ac.jp/~yohta/netscape/ \
		${RESOURCE_SITES}
DISTFILES=	${EXTRACT_ONLY} ${RESOURCE_FILE}

MAINTAINER=	sada@FreeBSD.ORG

RUN_DEPENDS?= \
	${PREFIX}/bin/${BROWSER}:${PORTSDIR}/www/netscape4-${BROWSER_NAME} \
	${FONT_DEPEND}

EXTRACT_ONLY=	${JAPANIZE_KIT}
MAN1=		ja-${BROWSER_NAME}.1
MANLANG=	ja
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/netscape-ja_euc

BROWSER=	${BROWSER_NAME}-${BROWSER_VERSION}
BROWSER_NAME?=	communicator
BROWSER_VER=	4
BROWSER_VERSION?= 4.07
FILES_DIR?=	${FILESDIR}
FONT_DEPEND=	\
	${PKG_DBDIR}/ja-netscape-fonts-1.0:${PORTSDIR}/japanese/netscape-fonts
JAPANIZE_KIT?=	communicator-ja-euc-v407-export.generic-generic-generic.tar.gz
LANG=		ja_JP.EUC
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER@;${BROWSER};g" \
			-e "s;@LANG@;${LANG};g"
MANDIR=		${MANPREFIX}/man/${MANLANG}
MANFILE?=	${FILES_DIR}/${MAN1}
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR?=	lib/netscape
PLIST_SUB=	NSUBDIR=${NSUBDIR} BROWSER=${BROWSER} LANG=${LANG}
# Below two lines could be overwritten,
# and you could create new ja-netscape4 with new resource.
RESOURCE_FILE?= ja-netscape-resource-${BROWSER_VERSION}.gz
RESOURCE_SITES?= http://WWW.JP.FreeBSD.ORG/~sada/distfiles/ \
		http://WWW.FreeBSD.ORG/~sada/distfiles/

.SILENT:

post-extract:
	${GZCAT} ${DISTDIR}/${RESOURCE_FILE} >${WRKSRC}/Netscape

do-configure:
	${MAKESCRIPT} ${FILES_DIR}/start.sh.in >${WRKDIR}/start.sh

do-install:
	${INSTALL_DATA} ${FILES_DIR}/preferences.js ${NDIR}
	${MKDIR} ${NDIR}/locale
	${LN} -sf /usr/share/locale/en_US.ISO_8859-1 ${NDIR}/locale/${LANG}
	${MKDIR} ${NDIR}/${LANG}
.for f in Netscape about mail.msg netscape.cfg plugins splash
	${INSTALL_DATA} ${WRKSRC}/$f ${NDIR}/${LANG}/
.endfor
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/nethelp-v406.nif \
		-C ${NDIR}/${LANG}
	${INSTALL_SCRIPT} ${WRKDIR}/start.sh ${PREFIX}/bin/ja-${BROWSER}
	${LN} -sf ja-${BROWSER} ${PREFIX}/bin/netscape
	${MKDIR} ${MANDIR}/man1
	${INSTALL_MAN} ${MANFILE} ${MANDIR}/man1

.include <bsd.port.mk>
