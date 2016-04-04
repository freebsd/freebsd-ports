# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	unigine-valley
PORTVERSION=	1.0
CATEGORIES=	games benchmarks linux
MASTER_SITES=	http://de1-dl.techpowerup.com/Benchmarking/ \
		http://nl1-dl.techpowerup.com/Benchmarking/ \
		http://uk1-dl.techpowerup.com/Benchmarking/ \
		http://us1-dl.techpowerup.com/Benchmarking/ \
		http://us2-dl.techpowerup.com/Benchmarking/
PKGNAMEPREFIX=	linux-
DISTNAME=	Unigine_Valley-${PORTVERSION}
EXTRACT_SUFX=	.run

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Unigine Valley Benchmark, basic version, linux binaries

LICENSE=	Proprietary
LICENSE_NAME=	Unigine "Basic" License
LICENSE_FILE=	${.CURDIR}/pkg-license
LICENSE_PERMS=	no-dist-sell no-pkg-sell no-dist-mirror no-pkg-mirror

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs openal-soft
USE_LDCONFIG=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	NVIDIA_GL
NVIDIA_GL_DESC=	Use GL driver from nvidia-driver
NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
NVIDIA_GL_VARS_OFF=	USE_LINUX_APPS+=dri

do-extract:
	@${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${TAIL} -n 1491255 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -
	${PRINTF} "#\!/bin/sh\ncd ${DATADIR}/bin/\n" > ${WRKDIR}/${PORTNAME}
	${ECHO} 'export LD_LIBRARY_PATH=./x86:$$LD_LIBRARY_PATH' >> ${WRKDIR}/${PORTNAME}
	${ECHO} './browser_x86 -config ../data/launcher/launcher.xml' >> ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./data ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./bin ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./documentation ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
