# New ports collection makefile for: Netscape browser with Japanese resources
# Date created:		13 Mar 1998
# Whom:			sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netscape-${BROWSER_ARC}
PORTVERSION=	${BROWSER_VERSION}
CATEGORIES=	japanese www
MASTER_SITES?=	${MASTER_SITE_PORTS_JP} \
		http://www.bres.tsukuba.ac.jp/~yohta/netscape/
DISTNAME?=	communicator-ja-euc-v407-export.generic-generic-generic

MAINTAINER?=	sada@FreeBSD.org

# ?= for ports that include this Makefile
RUN_DEPENDS?=	${PREFIX}/bin/${BROWSER_ARC}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape${BROWSER_VER}-${BROWSER_NAME}
RUN_DEPENDS+=	${PKG_DBDIR}/ja-bdf-fonts-1.0:${PORTSDIR}/japanese/bdf-fonts

.if (!defined(BROWSER_VERSION) || ${PORTVERSION} == "4.76")
BROKEN=		"has a serious security hole, use 4.77 instead"
.endif

MAN1=		ja-netscape.1
MANLANG=	ja
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL
PLIST_SUB=	BROWSER=${BROWSER_ARC} NSUBDIR=${NSUBDIR} LANG=${LANG} VER=${BROWSER_VER}
WRKSRC=		${WRKDIR}/netscape-ja_euc

BROWSER_NAME?=	communicator
BROWSER_ARC?=	${BROWSER_NAME}
BROWSER_BIN?=	${BROWSER_ARC}-${BROWSER_VERSION}.bin
BROWSER_CMD?=	ja-${BROWSER_ARC}-${BROWSER_VER}
BROWSER_VER?=	4
BROWSER_VERSION?= 4.08
LANG=		ja_JP.EUC
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER@;${BROWSER_ARC}-${BROWSER_VERSION};g" \
			-e "s;@BROWSER_BIN@;${BROWSER_BIN};g" \
			-e "s;@LANG@;${LANG};g"
MANDIR=		${MANPREFIX}/man/${MANLANG}
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR?=	lib/netscape
NETHELP?=	nethelp-v406
START_SCRIPT?=	${MASTERDIR}/files/start.sh.in

.SILENT:

do-configure:
	${MAKESCRIPT} ${START_SCRIPT} >${WRKDIR}/start.sh
	${MAKESCRIPT} ${WRKSRC}/Netscape.ad-ja_euc \
	 | ${SED} "s/-dt-interface system-medium-\*-\*-S\*-\*-\*-\*-\*-\*-\*-\*-\*:/-misc-fixed-medium-r-normal--14-\*-\*-\*-\*-\*-iso8859-1; -misc-fixed-medium-r-normal--14-*-*-*-*-*-jisx0208.1983-0; -misc-fixed-medium-r-normal--14-*-*-*-*-*-jisx0201.1976-0:/;" \
	 >${WRKDIR}/Netscape
	${MAKESCRIPT} ${MASTERDIR}/files/INSTALL >${PKGINSTALL}
	${CP} ${WRKSRC}/about ${WRKDIR}/about
.if (${BROWSER_NAME} == navigator)
	${CP} ${WRKDIR}/Netscape ${WRKDIR}/Netscape.orig
	${SED} "s/Communicator/Navigator/g" ${WRKDIR}/Netscape.orig \
	 > ${WRKDIR}/Netscape
	${SED} "s/Communicator/Navigator/g" ${WRKSRC}/about \
	 > ${WRKDIR}/about
.endif
	${CP} ${WRKDIR}/about ${WRKDIR}/splash

do-install:
	${INSTALL_DATA} ${MASTERDIR}/files/preferences.js ${NDIR}/
	${MKDIR} ${NDIR}/locale
	${LN} -sf /usr/share/locale/en_US.ISO_8859-1 ${NDIR}/locale/${LANG}
	${MKDIR} ${NDIR}/${LANG}
	${INSTALL_DATA} ${WRKSRC}/netscape.cfg ${NDIR}/
.for f in mail.msg plugins
	${INSTALL_DATA} ${WRKSRC}/$f ${NDIR}/${LANG}/
.endfor
.for f in Netscape about splash
	${INSTALL_DATA} ${WRKDIR}/$f ${NDIR}/${LANG}/
.endfor
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/${NETHELP}.nif \
		${EXTRACT_AFTER_ARGS} -C ${NDIR}/${LANG}
	${INSTALL_SCRIPT} ${WRKDIR}/start.sh ${PREFIX}/bin/${BROWSER_CMD}
	${LN} -sf ${BROWSER_CMD} ${PREFIX}/bin/netscape.run
	${MKDIR} ${MANDIR}/man1
	${INSTALL_MAN} ${MASTERDIR}/files/${MAN1} ${MANDIR}/man1

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
