# Created by: vanilla@
# $FreeBSD$

PORTNAME=	gcin
PORTVERSION=	2.8.6
PORTREVISION=	1
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://hyperrate.com/gcin-source/
PKGNAMESUFFIX=	-qt5
EXTRACT_ONLY=	gcin-${PORTVERSION}.tar.xz

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Traditional Chinese input utility in X

LICENSE=	LGPL21

LIB_DEPENDS=	libgcin-im-client.so:chinese/gcin

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/qt5-im
USES=		compiler:c++11-lang gmake pkgconfig tar:xz
USE_QT5=	qdbus qmake_build buildtools_build core gui
USE_CXXSTD=	c++11
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MKDIR="${MKDIR}"

PLIST_FILES=	${QT_PLUGINDIR}/platforminputcontexts/libgcinplatforminputcontextplugin.so

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 60
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang60:devel/llvm60
CPP=		${LOCALBASE}/bin/clang-cpp60
CC=		${LOCALBASE}/bin/clang60
CXX=		${LOCALBASE}/bin/clang++60
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g; \
		s,%%MOC%%,${MOC},;' ${WRKSRC}/Makefile
	@${ECHO} "XXXX: ${COMPILER_VERSION}"

.include <bsd.port.post.mk>
