PORTNAME=	newtonsoft-json
PORTVERSION=	9.0.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Popular high-performance JSON framework for .NET

LICENSE=	MIT

USES=		mono

USE_GITHUB=	yes
GH_ACCOUNT=	JamesNK
GH_PROJECT=	Newtonsoft.Json

SUB_FILES=	Newtonsoft.Json.pc

NO_ARCH=	yes

PLIST_FILES=	lib/mono/Newtonsoft.Json/Newtonsoft.Json.dll \
		lib/mono/gac/Newtonsoft.Json/7.0.0.0__b9a188c8922137c6/Newtonsoft.Json.dll \
		lib/mono/gac/Newtonsoft.Json/7.0.0.0__b9a188c8922137c6/Newtonsoft.Json.pdb \
		libdata/pkgconfig/Newtonsoft.Json.pc

.include <bsd.port.pre.mk>

.if defined(MONO_DEFAULT) && ${MONO_DEFAULT} > 6
BROKEN=		fails to build with Mono version ${MONO_DEFAULT}: Failure adding assembly dbus-sharp.dll to the cache: Strong name cannot be verified for delay-signed assembly
.endif

do-build:
	(cd ${WRKSRC}/Src/Newtonsoft.Json && ${SETENV} ${MAKE_ENV} xbuild Newtonsoft.Json.csproj \
		/property:SignAssembly=true \
		/property:AssemblyOriginatorKeyFile=Dynamic.snk \
		/property:Configuration=Release \
		/property:DefineConstants='SIGNED NET45 TRACE')

do-install:
	(cd ${WRKSRC}/Src/Newtonsoft.Json/bin/Release/Net45 && \
		${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil \
		/root ${STAGEDIR}${PREFIX}/lib/ \
		/package Newtonsoft.Json /i Newtonsoft.Json.dll)
	(cd ${WRKDIR} && ${INSTALL_DATA} Newtonsoft.Json.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig)

.include <bsd.port.post.mk>
