# New ports collection makefile for:	zh-wangttf
# Date created:		19 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wangttf
PORTVERSION=	1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/wangttf/
DISTFILES=	wcl-01.ttf.bz2 wcl-02.ttf.bz2 wcl-03.ttf.bz2 wcl-04.ttf.bz2 \
		wcl-05.ttf.bz2 wcl-06.ttf.bz2 wcl-07.ttf.bz2 wcl-08.ttf.bz2 \
		wcl-09.ttf.bz2 wcl-10.ttf.bz2
EXTRACT_ONLY=

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

WANT_CJK?=	NO
WANT_GS6?=	NO
WANT_X?=	YES

DIST_SUBDIR=	zh-wangttf
USE_BZIP2=	yes
USE_XLIB=	yes
NO_BUILD=	yes
SHAREMODE=	644
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} XFREE86_VERSION=${XFREE86_VERSION} \
		WANT_CJK=${WANT_CJK} WANT_GS6=${WANT_GS6} WANT_X=${WANT_X}

.include <bsd.port.pre.mk>

.if ${WANT_CJK} != "NO"
RUN_DEPENDS+=	bg5latex:${PORTSDIR}/chinese/CJK
.endif
.if ${WANT_GS6} != "NO"
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/CJK/CMap/B5pc-H:${PORTSDIR}/chinese/ghostscript6
.endif
.if ${XFREE86_VERSION} == 3 && ${WANT_X} != "NO"
RUN_DEPENDS+=	mkfontdir.pl:${PORTSDIR}/x11-servers/XttXF86srv-common
.endif

do-install:
	@${MKDIR} ${FONTDIR}
.for i in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${FONTDIR}
	@${EXTRACT_CMD} -dv ${FONTDIR}/${i}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/wangttf.txt ${FONTDIR}
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
