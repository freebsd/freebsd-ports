# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openshadinglanguage
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Advanced shading language for production GI renderers

LICENSE=	BSD

BUILD_DEPENDS=	llvm-config33:${PORTSDIR}/devel/llvm33 \
		clang33>=3.3_3:${PORTSDIR}/lang/clang33
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libOpenImageIO.so:${PORTSDIR}/graphics/openimageio
RUN_DEPENDS=	llvm-config33:${PORTSDIR}/devel/llvm33

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenShadingLanguage
GH_TAGNAME=	Release-${PORTVERSION}
GH_COMMIT=	18671dc

WRKSRC=		${WRKDIR}/imageworks-OpenShadingLanguage-${GH_COMMIT}/src

CMAKE_ARGS=	-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config33"
USE_LDCONFIG=	yes
USES=		bison cmake:outsource

.include <bsd.port.options.mk>

.if ${ARCH} == i386 && ! ${MACHINE_CPU:Mi586}
IGNORE=		CPUTYPE must be i586 or higher in /etc/make.conf
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.37:${PORTSDIR}/textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex
CXXFLAGS+=	-I${LOCALBASE}/include/flex
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' \
		${WRKSRC}/liboslexec/serialize-bc.bash

post-install:
.for LNAME in oslcomp oslexec oslquery testshade
	${MV} ${STAGEDIR}${PREFIX}/lib/lib${LNAME}.so ${STAGEDIR}${PREFIX}/lib/lib${LNAME}.so.1
	${LN} -s lib${LNAME}.so.1 ${STAGEDIR}${PREFIX}/lib/lib${LNAME}.so
.endfor

.include <bsd.port.mk>
