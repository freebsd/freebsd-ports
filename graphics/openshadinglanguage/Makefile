# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openshadinglanguage
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Advanced shading language for production GI renderers

LICENSE=	BSD

BUILD_DEPENDS=	llvm>=3.1:${PORTSDIR}/devel/llvm \
		flex>=2.5.37:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		OpenImageIO:${PORTSDIR}/graphics/openimageio
RUN_DEPENDS=	llvm>=3.1:${PORTSDIR}/devel/llvm

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenShadingLanguage
GH_TAGNAME=	Release-${PORTVERSION}
GH_COMMIT=	18671dc

WRKSRC=		${WRKDIR}/imageworks-OpenShadingLanguage-${GH_COMMIT}/src

CMAKE_ARGS=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex \
		-DUSE_TBB:BOOL=OFF
CXXFLAGS+=	-I${LOCALBASE}/include/flex
USE_LDCONFIG=	yes
USES=		bison cmake:outsource

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BUILD_DEPENDS+=	clang:${PORTSDIR}/lang/clang
.endif

.if ${ARCH} == i386
CFLAGS+=	-march=i586
.endif

post-install:
.for LNAME in oslcomp oslexec oslquery testshade
	cd ${PREFIX}/lib && ${MV} -f lib${LNAME}.so lib${LNAME}.so.1
	cd ${PREFIX}/lib && ${LN} -sf lib${LNAME}.so.1 lib${LNAME}.so
.endfor

.include <bsd.port.post.mk>
