# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	unigine-heaven
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	games benchmarks linux
MASTER_SITES=	http://de1-dl.techpowerup.com/Benchmarking/ \
		http://nl1-dl.techpowerup.com/Benchmarking/ \
		http://uk1-dl.techpowerup.com/Benchmarking/ \
		http://us1-dl.techpowerup.com/Benchmarking/ \
		http://us2-dl.techpowerup.com/Benchmarking/
PKGNAMEPREFIX=	linux-
DISTNAME=	Unigine_Heaven-${PORTVERSION}
EXTRACT_SUFX=	.run

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Unigine Heaven Benchmark, basic version, linux binaries

LICENSE=	Proprietary
LICENSE_NAME=	Unigine "Basic" License
LICENSE_TEXT=	Binary only, License text not available. Free-to-use + no-redistribution implied from homepage
LICENSE_PERMS=	no-dist-sell no-pkg-sell no-dist-mirror no-pkg-mirror

ONLY_FOR_ARCHS=	i386 amd64
USES=		linux
USE_LINUX=	dri openal-soft xorglibs
USE_LDCONFIG=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${TAIL} -n 1098568 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -
	${PRINTF} "#\!/bin/sh\ncd ${DATADIR}/bin/\n" > ${WRKDIR}/${PORTNAME}
	${ECHO} 'export LD_LIBRARY_PATH=./x86:$$LD_LIBRARY_PATH' >> ${WRKDIR}/${PORTNAME}
	${ECHO} './browser_x86 -config ../data/launcher/launcher.xml' >> ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./data ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./bin ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./documentation ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
