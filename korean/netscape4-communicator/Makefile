# New ports collection makefile for: Netscape browser with Korean resources
# Version required:	4
# Date created:		25 Oct 1998
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#
# based on japanese/netscape4-*

DISTNAME=	ko-netscape-${BROWSER}-${BROWSER_VERSION}
CATEGORIES=	korean www
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/users/cjh/netscape-ko/ \
		http://www.kr.freebsd.org/~cjh/freetime/mozilla/netscape-ko/
DISTFILES=	${KOREAN_KIT}.tar.gz

MAINTAINER?=	cjh@kr.freebsd.org

# ?= for ports that include this Makefile
RUN_DEPENDS?=	${PREFIX}/bin/${BROWSER}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape4-${BROWSER}
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/local/hgm12.pcf.gz:${PORTSDIR}/korean/hanyangfonts \
		${X11BASE}/lib/X11/fonts/local/mzgt16h1.pcf.gz:${PORTSDIR}/korean/mizifont

NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL
PLIST=		${.CURDIR}/pkg/PLIST
PLIST_SUB=	NSUBDIR=${NSUBDIR} LANG=${LANG}
WRKSRC=		${WRKDIR}/${KOREAN_KIT}
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR?=	lib/netscape
FILESDIR?=	${.CURDIR}/files

# should be changed by versions
BROWSER?=       communicator
BROWSER_BIN?=   ${BROWSER}-${BROWSER_VERSION}.bin
BROWSER_CMD?=   ko-${BROWSER}-4
BROWSER_VERSION?= 4.08
NETHELP?=	nethelp-v403
KOREAN_KIT?=	netscape-v408.generic-generic-generic-19990612

LANG=		ko_KR.EUC
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER@;${BROWSER};g" \
			-e "s;@BROWSER_BIN@;${BROWSER_BIN};g" \
			-e "s;@LANG@;${LANG};g"
TAR=		/usr/bin/tar

.if ${BROWSER_VERSION} == 4.08
DIST_SUBDIR=    korean-netscape
.endif

.SILENT:

do-configure:
	${MAKESCRIPT} ${FILESDIR}/start.sh.in >${WRKDIR}/start.sh
	${MAKESCRIPT} ${WRKSRC}/Netscape.ad-ko >${WRKSRC}/Netscape
	${MAKESCRIPT} ${FILESDIR}/INSTALL >${PKGINSTALL}
	# make navigator resource
.if defined(BROWSER) && ${BROWSER} == navigator
	${SED} -e "s;Communicator;Navigator;g" \
		${WRKSRC}/about > ${WRKDIR}/about
	${SED} -e "s;Communicator;Navigator;g" \
		${WRKSRC}/splash > ${WRKDIR}/splash
.else
	${CP} ${WRKSRC}/about ${WRKDIR}/about
	${CP} ${WRKSRC}/splash ${WRKDIR}/splash
.endif


do-install:
	${INSTALL_DATA} ${FILESDIR}/preferences.js ${NDIR}
	${MKDIR} ${NDIR}/locale
	${LN} -sf /usr/share/locale/en_US.ISO_8859-1 ${NDIR}/locale/${LANG}
	${MKDIR} ${NDIR}/${LANG}
	${INSTALL_DATA} ${WRKSRC}/netscape.cfg ${NDIR}/
.for f in Netscape mail.msg plugins LICENSE.ko
	${INSTALL_DATA} ${WRKSRC}/$f ${NDIR}/${LANG}/
.endfor
.for f in about splash
	${INSTALL_DATA} ${WRKDIR}/$f ${NDIR}/${LANG}/
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/start.sh ${PREFIX}/bin/ko-${BROWSER}
	${LN} -sf ko-${BROWSER} ${PREFIX}/bin/netscape
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/${NETHELP}.nif \
		${EXTRACT_AFTER_ARGS} -C ${NDIR}/${LANG}
	${INSTALL_SCRIPT} ${WRKDIR}/start.sh ${PREFIX}/bin/${BROWSER_CMD}
	${TAR} -C ${NDIR}/${LANG} -x -z -v -f ${WRKSRC}/${NETHELP}.nif

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
