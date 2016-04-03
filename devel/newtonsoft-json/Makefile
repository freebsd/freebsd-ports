# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	newtonsoft-json
PORTVERSION=	8.0.3
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Popular high-performance JSON framework for .NET

LICENSE=	MIT

USES=		mono

USE_GITHUB=	yes
GH_ACCOUNT=	JamesNK
GH_PROJECT=	Newtonsoft.Json

SUB_FILES=	Newtonsoft.Json.pc

PLIST_FILES=	lib/mono/Newtonsoft.Json/Newtonsoft.Json.dll \
		lib/mono/gac/Newtonsoft.Json/7.0.0.0__b9a188c8922137c6/Newtonsoft.Json.dll \
		lib/mono/gac/Newtonsoft.Json/7.0.0.0__b9a188c8922137c6/Newtonsoft.Json.dll.mdb \
		libdata/pkgconfig/Newtonsoft.Json.pc

do-build:
	(cd ${WRKSRC}/Src/Newtonsoft.Json && ${SETENV} ${MAKE_ENV} xbuild Newtonsoft.Json.csproj \
		/property:SignAssembly=true \
		/property:AssemblyOriginatorKeyFile=Dynamic.snk \
		/property:Configuration=Release \
		/property:DefineConstants='SIGNED NET45 TRACE')
	(cd ${WRKSRC}/Src/Newtonsoft.Json/bin/Release/Net45 && \
		${SETENV} ${MAKE_ENV} monodis Newtonsoft.Json.dll --output=Newtonsoft.Json.il)
	(cd ${WRKSRC}/Src/Newtonsoft.Json/bin/Release/Net45 && \
		${SETENV} ${MAKE_ENV} ilasm /dll /key:../../../Dynamic.snk Newtonsoft.Json.il)

do-install:
	(cd ${WRKSRC}/Src/Newtonsoft.Json/bin/Release/Net45 && \
		${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil \
		/root ${STAGEDIR}${PREFIX}/lib/ \
		/package Newtonsoft.Json /i Newtonsoft.Json.dll)
	(cd ${WRKDIR} && ${INSTALL_DATA} Newtonsoft.Json.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig)

.include <bsd.port.mk>
