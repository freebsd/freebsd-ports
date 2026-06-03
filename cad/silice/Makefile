PORTNAME=	silice
DISTVERSION=	g20260322
PORTREVISION=	1
CATEGORIES=	cad java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language that simplifies prototyping and writing algorithms for FPGAs
WWW=		https://github.com/sylefeb/Silice

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE_GPLv3

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}edalize>0:cad/py-edalize@${PY_FLAVOR} # examples also require xtclsh from Xilinx

USES=		cmake:noninja java python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	sylefeb
GH_PROJECT=	Silice
GH_TAGNAME=	73bebc45
GH_TUPLE=	ultraembedded:fat_io_lib:0ef5c2bb:fat_io_lib/learn-silice/classroom/soc_wave_player/firmware/fat_io_lib \
		sylefeb:tinygpus:498be1b8:tinygpus/projects/tinygpus \
		sylefeb:LibSL-small:b1942d5:libslsmall/projects/tinygpus/demos/q5k/qrepack/LibSL-small \
		pybind:pybind11:2dd52544:pybind11/python/pybind11 \
		sylefeb:LibSL-small:b1942d59:libslsmall/src/libs/LibSL-small

SHEBANG_GLOB=	*.sh *.py

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/silice-make.py ${STAGEDIR}${PREFIX}/bin
	${REINPLACE_CMD} \
		-i '' \
		-e 's|frameworks_dir = os.path.realpath(os.path.join(make_dir,"../frameworks/"))|frameworks_dir = "${DATADIR}/frameworks"|' \
		${STAGEDIR}${PREFIX}/bin/silice-make.py
	cd ${WRKSRC} && ${COPYTREE_SHARE} frameworks ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
