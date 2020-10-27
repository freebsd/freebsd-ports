# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openbve
PORTVERSION=	1.7.2.0
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	e8c81970ea0e3b9bee1192d85cf67ef3aa31d971.diff:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Realistic 3D train/railway simulator

LICENSE=	PD

BUILD_DEPENDS=	msbuild:devel/msbuild \
		gdate:sysutils/coreutils
LIB_DEPENDS=	libgdiplus.so:x11-toolkits/libgdiplus

USE_GITHUB=	yes
GH_ACCOUNT=	leezer3
GH_PROJECT=	OpenBVE

USES=		gmake mono:nuget openal:soft
MAKEFILE=	makefile
ALL_TARGET=	all-release

NUGET_DEPENDS=	CS-Script.lib=3.30.3 \
		DotNetZip=1.13.8 \
		NAudio.Vorbis=1.2.0 \
		NAudio=1.10.0 \
		NLayer.NAudioSupport=1.0.0 \
		NLayer=1.12.0 \
		NVorbis=0.10.1 \
		OpenTK.GLControl=3.1.0 \
		OpenTK=3.2.0 \
		Prism.Core=7.2.0.1422 \
		ReactiveProperty.Core=7.1.0 \
		ReactiveProperty=7.1.0 \
		SharpCompress=0.25.1 \
		System.Buffers=4.5.1 \
		System.ComponentModel.Annotations=4.7.0 \
		System.Memory=4.5.4 \
		System.Numerics.Vectors=4.5.0 \
		System.Reactive=4.4.1 \
		System.Runtime.CompilerServices.Unsafe=4.7.1 \
		System.Threading.Tasks.Extensions=4.5.4 \
		System.ValueTuple=4.5.0 \
		Ude.NetStandard=1.2.0

DATADIR=	${PREFIX}/lib/${PORTNAME}
PORTDOCS=	changelog.md credits.md routes-and-trains.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	@${LN} -sf OpenTK.3.2.0 ${_NUGET_PACKAGEDIR}/OpenTK.3.2

post-patch:
	@${REINPLACE_CMD} -e '/Unix/s,bash,sh,' \
		${WRKSRC}/source/OpenBVE/OpenBve.csproj
	@${REINPLACE_CMD} -e '/TargetFrameworkVersion/s,4\.7\.2,4.6.1,' \
		${WRKSRC}/source/TrainEditor2/TrainEditor2.csproj

do-install:
# This is Windows only, so can be removed
	${RM} ${WRKSRC}/bin_release/AtsPluginProxy.*
	${CP} -a ${WRKSRC}/bin_release ${STAGEDIR}${DATADIR}
.for script program in openbve OpenBve openbve-objectviewer ObjectViewer \
    openbve-routeviewer RouteViewer
	${PRINTF} '#!/bin/sh\n\nexec mono ${DATADIR}/${program}.exe\
		"$$@"\n' > ${STAGEDIR}${PREFIX}/bin/${script}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${script}
.endfor
	${INSTALL_MAN} ${WRKSRC}/debian/*.6 ${STAGEDIR}${MANPREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/debian/openbve.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/debian/openbve.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${REINPLACE_CMD} -e 's,linux,${OPSYS:tl},' \
		${STAGEDIR}${DATADIR}/OpenTK.dll.config

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/debian/,} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
