# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.07
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id: Makefile,v 1.7 1998/11/16 19:52:58 sada Exp $
#

DISTNAME=	ja-netscape-${BROWSER}
CATEGORIES=	japanese www
MASTER_SITES=	http://www.bres.tsukuba.ac.jp/~yohta/netscape/
DISTFILES?=	communicator-ja-euc-v407-export.generic-generic-generic.tar.gz

MAINTAINER=	sada@freebsd.org

RUN_DEPENDS?= \
	${PREFIX}/bin/${BROWSER}:${PORTSDIR}/www/netscape4-${BROWSER_NAME} \
	${FONT_DEPEND}

MAN1=		ja-${BROWSER_NAME}.1
MANLANG=	ja
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/netscape-ja_euc

BROWSER=	${BROWSER_NAME}-${BROWSER_VERSION}
BROWSER_NAME?=	communicator
BROWSER_VER=	4
BROWSER_VERSION?= 4.07
LANG=		ja_JP.EUC
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR?=	lib/netscape
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER@;${BROWSER};g" \
			-e "s;@LANG@;${LANG};g"
MANDIR=		${MANPREFIX}/man/${MANLANG}
MANFILE?=	${FILESDIR}/${MAN1}
PLIST_SUB=	NSUBDIR=${NSUBDIR} BROWSER=${BROWSER} LANG=${LANG}
FONT_DEPEND= \
	${PKG_DBDIR}/ja-netscape-fonts-1.0:${PORTSDIR}/japanese/netscape-fonts

.SILENT:

do-configure:
	${MAKESCRIPT} ${FILESDIR}/start.sh.in >${WRKDIR}/start.sh
.if defined(USE_16DOT_FONT)
	${MAKESCRIPT} ${WRKSRC}/Netscape.ad-ja_euc >${WRKSRC}/Netscape
.else
	${MAKESCRIPT} ${WRKSRC}/Netscape.ad-ja_euc \
	| ${SED} -f ${FILESDIR}/14dot.sed >${WRKSRC}/Netscape
.endif

do-install:
	${INSTALL_DATA} ${FILESDIR}/preferences.js ${NDIR}
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
