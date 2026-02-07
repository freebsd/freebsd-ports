PORTNAME=	fsharp
PORTVERSION=	10.2.1
PORTREVISION=	2
CATEGORIES=	lang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Functional and object-oriented language for the .NET platform
WWW=		https://fsharp.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	msbuild:devel/msbuild
TEST_DEPENDS=	libgdiplus>=0:x11-toolkits/libgdiplus

USES=		gmake mono:nuget pkgconfig
USE_GITHUB=	yes
MAKE_JOBS_UNSAFE=	Build not parallelizable
NUGET_LAYOUT=	legacy
NO_ARCH=	yes

do-test:
	${MKDIR} ${WRKDIR}/bin
	echo "#!/bin/sh" > ${WRKDIR}/bin/fsharpc
	echo 'exec ${LOCALBASE}/bin/mono ${WRKSRC}/Release/net40/bin/fsc.exe "$$@"' >> ${WRKDIR}/bin/fsharpc
	${CHMOD} 0755 ${WRKDIR}/bin/fsharpc
	(cd ${WRKSRC}/tests/fsharp/core; \
		${ENV} \
			PATH=${WRKDIR}/bin:${PATH} \
			MONO_PATH=${WRKSRC}/Release/net40/bin \
			./run-all.sh)

.include <bsd.port.pre.mk>

.if defined(MONO_DEFAULT) && ${MONO_DEFAULT} > 6
BROKEN=		fails to build with Mono version ${MONO_DEFAULT}: A unique overload for method 'GetFileNameWithoutExtension' could not be determined based on type information prior to this program point
.endif

.include <bsd.port.post.mk>
