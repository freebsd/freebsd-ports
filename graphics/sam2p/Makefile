# Created by: ijliao
# $FreeBSD$

PORTNAME=	sam2p
PORTVERSION=	0.49.2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts raster (bitmap) image formats into PS or PDF files

LICENSE=	GPLv2

RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		tif22pnm:${PORTSDIR}/graphics/tif22pnm

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		gmake jpeg:run perl5
USE_PERL5=	build
USE_GCC=	any
USE_GHOSTSCRIPT_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_pts_bash="${SH}"
CONFIGURE_ARGS=	--enable-gif
MAKE_ARGS=	CXXX="${CXX}" LDALL="${CXX}" CXXFLAGSB="${CXXFLAGS}" CC="${CC}" CXX="${CXX}"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
