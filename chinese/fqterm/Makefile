# New ports collection makefile for:	fqterm
# Date created:					1 Jun 2008
# Whom:							Denise H. G. <darcsis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fqterm
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	zh-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-r569${SUTRACT_SUFFIX}

MAINTAINER=	darcsis@gmail.com
COMMENT=	FQTerm is a BBS client for BSD/Linux

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-install pkg-deinstall ${PORTNAME}.desktop
USE_XORG=	x11 ice xext xt xaw xpm xi xproto xextproto
USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network script qt3support imageformats \
		codecs-cn codecs-tw codecs-jp codecs-kr \
		qmake_build moc_build rcc_build uic_build linguist_build

HAS_CONFIGURE=	yes
USE_DOS2UNIX=	src/ui/popwidget.cpp
USE_GMAKE=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_INSTALL_PREFIX=	${PREFIX}
CMAKE_ARGS=	-Wno-dev

DATADIR=	${PREFIX}/share/FQTerm

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${MKDIR} build
	@cd ${WRKSRC}/build && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${WRKSRC}

do-build:
	@cd ${WRKSRC}/build && ${GMAKE}

do-install:
	@cd ${WRKSRC}/build && ${GMAKE}	install/strip
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop \
		${PREFIX}/share/applications

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
