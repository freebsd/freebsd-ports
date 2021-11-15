# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	unigine-sanctuary
PORTVERSION=	2.3
CATEGORIES=	benchmarks linux
MASTER_SITES=	https://assets.unigine.com/d/
PKGNAMEPREFIX=	linux-
DISTNAME=	Unigine_Sanctuary-${PORTVERSION}
EXTRACT_SUFX=	.run

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Unigine GPU benchmark depicting a Gothic chapel

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	precompiled, binary-only software for GNU/Linux

USES=		linux
USE_LINUX=	dri openal-soft xorglibs
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAIL} -n 107856 ${DISTDIR}/${DISTFILES} | ${TAR} xzf - -C ${WRKSRC}

post-patch:
# Avoid clash with other Unigine benchmarks
.for script in 1024x768_windowed 1920x1080_fullscreen
	@${SED} -e 's,\./bin,${DATADIR}/bin,' ${WRKSRC}/${script}.sh \
		> ${WRKSRC}/${PORTNAME}_${script}.sh
.endfor

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Sanctuary ${STAGEDIR}${DATADIR}/bin
	${INSTALL_LIB} ${WRKSRC}/bin/libUnigine_x86.so \
		${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}*sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
