# New ports collection makefile for: Netscape browser with Korean resources
# Date created:		25 Oct 1998
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#
# based on japanese/netscape4-*

PORTNAME=	netscape-${BROWSER_ARC}
PORTVERSION=	${BROWSER_VERSION}
CATEGORIES=	korean www
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/users/cjh/netscape-ko/ \
		http://www.kr.freebsd.org/~cjh/freetime/mozilla/netscape-ko/
DISTNAME=	${KOREAN_KIT}

MAINTAINER?=	cjh@FreeBSD.org

# ?= for ports that include this Makefile
RUN_DEPENDS?=	${LOCALBASE}/bin/${BROWSER_ARC}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape${BROWSER_VER}-${BROWSER_NAME}
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf \
		/compat/linux/usr/share/locale/ko/LC_MESSAGES/SYS_LC_MESSAGES:${PORTSDIR}/korean/linux_locale

NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/INSTALL
PLIST_SUB=	NSUBDIR=${NSUBDIR} LANG=${LANG} \
		BROWSER=${BROWSER_ARC} VER=${BROWSER_VER}
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR?=	lib/netscape-linux

# should be changed by versions
BROWSER_NAME?=       communicator
BROWSER_ARC?=	${BROWSER_NAME}-linux
BROWSER_BIN?=   ${BROWSER_ARC}-${BROWSER_VERSION}.bin
BROWSER_CMD?=   ko-${BROWSER_ARC}-${BROWSER_VER}
BROWSER_VER?=	48
BROWSER_VERSION?= 4.8

# for old version(<4.5), font name substitution required.
# newer version use baekmuk-gulim should not be affected.
PREVFONTNAME=	kodig
NEWFONTNAME=	gulim

KOREAN_KIT?=	netscape-korean-kit-v476.20001031

NETHELP?=	nethelp-v451
START_SCRIPT?=	${MASTERDIR}/files/start.sh.in
ADDXRESOURCE?=	${MASTERDIR}/files/xresource.ad

LANG=		ko_KR.eucKR
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER@;${BROWSER_ARC}-${BROWSER_VERSION};g" \
			-e "s;@BROWSER_BIN@;${BROWSER_BIN};g" \
			-e "s;@LANG@;${LANG};g" \
			-e "s;-${PREVFONTNAME}-;-${NEWFONTNAME}-;g"

do-configure:
	${MAKESCRIPT} ${START_SCRIPT} >${WRKDIR}/start.sh
	# add FreeBSD-specific resource
	${MAKESCRIPT} ${WRKSRC}/Netscape.ad-ko >${WRKSRC}/Netscape.2.ad
	${CAT} ${WRKSRC}/Netscape.2.ad ${ADDXRESOURCE} \
		> ${WRKSRC}/Netscape
	${MAKESCRIPT} ${FILESDIR}/INSTALL >${PKGINSTALL}
	# make navigator resource
.if defined(BROWSER_NAME) && ${BROWSER_NAME} == navigator
	${SED} -e "s;Communicator;Navigator;g" \
		${WRKSRC}/about > ${WRKDIR}/about
	${SED} -e "s;Communicator;Navigator;g" \
		${WRKSRC}/splash > ${WRKDIR}/splash
.else
	${CP} ${WRKSRC}/about ${WRKDIR}/about
	${CP} ${WRKSRC}/splash ${WRKDIR}/splash
.endif

do-install:
	${INSTALL_DATA} ${MASTERDIR}/files/preferences.js ${NDIR}
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
	${INSTALL_SCRIPT} ${WRKDIR}/start.sh ${PREFIX}/bin/${BROWSER_CMD}
	${LN} -sf ${BROWSER_CMD} ${PREFIX}/bin/netscape.run
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/${NETHELP}.nif \
		${EXTRACT_AFTER_ARGS} -C ${NDIR}/${LANG}

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
