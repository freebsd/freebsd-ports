# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME?=	opencolorio
PORTVERSION=	1.0.8
PORTREVISION?=	0
CATEGORIES=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	Complete color management solution

LICENSE?=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenColorIO
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	8883824

.if !defined(OCIO_TOOLS)
USE_PYTHON=	2.6+
USE_LDCONFIG=	yes
.endif

USES=		cmake:outsource
CMAKE_ARGS?=	-DOCIO_BUILD_APPS:BOOL=OFF \
		-DOCIO_BUILD_JNIGLUE:BOOL=OFF \
		-DOCIO_BUILD_NUKE:BOOL=OFF \
		-DOCIO_BUILD_STATIC:BOOL=OFF \
		-DOCIO_BUILD_PYGLUE:BOOL=ON

MAKE_JOBS_SAFE?=	yes

PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX}

.if !defined(OCIO_TOOLS)
OPTIONS_DEFINE=		DOCS SSE
OPTIONS_DEFAULT=	DOCS SSE
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS) || defined(OCIO_TOOLS)
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=OFF
.else
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=ON
.endif

.if ${PORT_OPTIONS:MSSE}
CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=ON
.else
CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=OFF
.endif

.include <bsd.port.pre.mk>

.if ${CC:T} == "clang" && ${ARCH} == "i386" && ${OSVERSION} < 901000
# workaround for pr/165968
# was fixed in 9-STABLE before 9.1-RELEASE but not passed into 9-RELEASE
CFLAGS+=	-march=pentium2
.endif

post-patch:
.if defined(OCIO_TOOLS)
	@${FIND} ${WRKSRC}/src/apps -name "main.cpp" -exec \
		${REINPLACE_CMD} -e 's|namespace OIIO|//namespace OIIO|g' "{}" \;
.endif

.include <bsd.port.post.mk>
