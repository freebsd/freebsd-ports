# New ports collection makefile for:	zh Big5/GB-ized Netscape
# Date created:		11 Mar 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD: /tmp/pcvs/ports/chinese/netscape47-communicator/Attic/Makefile,v 1.4 2001-02-04 08:06:51 keith Exp $
#

PORTNAME=	netscape-${BROWSER_ARC}
PORTVERSION=	${BROWSER_VERSION}
CATEGORIES=	chinese www
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	${REGION}-nskit-${BROWSER_VERSION}

MAINTAINER=	keith@FreeBSD.org

# ?= is for ports that include this Makefile.
# We need Arphic because there's no font with all sizes to deal with Java.
RUN_DEPENDS?=	\
		${X11BASE}/lib/aout/zh-XFree86-aoutlibs-3.3.6:${.CURDIR}/../XFree86-aoutlibs \
		${LOCALBASE}/bin/${BROWSER_ARC}-${BROWSER_VERSION}:${PORTSDIR}/www/netscape${BROWSER_VER}-${BROWSER} \
		${LOCALBASE}/lib/aout/libxpg4-ns.so.2.0:${PORTSDIR}/www/libxpg4-ns \
		${X11BASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf

# These variables can be defined in ports that include this Makefile.
PKGNAMEPREFIX?=		zh_TW-
LOCALE?=		zh_TW.Big5
REGION?=		tw
BROWSER?=		communicator
BROWSER_VER?=		47
BROWSER_VERSION?=	4.76
BROWSER_ARC?=		${BROWSER}
BROWSER_BIN?=		${BROWSER_ARC}-${BROWSER_VERSION}.bin
BROWSER_CMD?=		${REGION}-${BROWSER_ARC}-${BROWSER_VER}
NSUBDIR?=		lib/netscape
NO_BUILD=		yes

NDIR=		${PREFIX}/${NSUBDIR}
PLIST_SUB=	BROWSER=${BROWSER_ARC} VER=${BROWSER_VER} NSUBDIR=${NSUBDIR} LOCALE=${LOCALE} REGION=${REGION} X11BASE=${X11BASE}
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
# RDIR is the resource directory.
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@LOCALBASE@;${LOCALBASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER_BIN@;${BROWSER_BIN};g" \
			-e "s;@LOCALE@;${LOCALE};g"
START_SCRIPT?=	${FILESDIR}/start.sh.in

.include <bsd.port.pre.mk>

do-configure:
	${MAKESCRIPT} ${START_SCRIPT} > ${WRKDIR}/${BROWSER_CMD}
	${MAKESCRIPT} ${FILESDIR}/INSTALL.in > ${WRKDIR}/pkg-install
	${MAKESCRIPT} ${FILESDIR}/MESSAGE.in > ${WRKDIR}/pkg-message
	${MAKESCRIPT} ${FILESDIR}/DEINSTALL.in > ${WRKDIR}/pkg-deinstall
.if (${BROWSER} == navigator)
	${SED} "s/Communicator/Navigator/g" ${WRKSRC}/Netscape.ad \
	 > ${WRKSRC}/Netscape
.else
	${CP} ${WRKSRC}/Netscape.ad ${WRKSRC}/Netscape
.endif

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_DATA} ${WRKSRC}/XLC_LOCALE.Big5 ${X11BASE}/lib/X11/locale/zh_TW.Big5/XLC_LOCALE
	${INSTALL_SCRIPT} ${WRKDIR}/${BROWSER_CMD} ${PREFIX}/bin/
	${LN} -sf ${BROWSER_CMD} ${PREFIX}/bin/netscape.run
.for f in font.properties.zh_GB2312 font.properties.zh_TW_Big5
	${INSTALL_DATA} ${WRKSRC}/$f ${NDIR}/java/classes
.endfor
	${MKDIR} ${NDIR}/${LOCALE}
	${CP} -R ${WRKSRC}/nethelp ${NDIR}/${LOCALE}/
.for f in BDP_LICENSE Netscape Netscape.WheelMouse
	${INSTALL_DATA} ${WRKSRC}/$f ${NDIR}/${LOCALE}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/preferences.js ${NDIR}/${LOCALE}
# I know Japanese & Korean's netscape ports all install netscape.cfg
# in ${NSUBDIR}, but then only a single locale's netscape.cfg is available
# to all users, which is IMHO unreasonable.
	${MKDIR} /usr/lib/X11/${LOCALE}/app-defaults
.for f in netscape.cfg netscape.jsc
	${INSTALL_DATA} ${WRKSRC}/$f /usr/lib/X11/${LOCALE}/app-defaults
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
