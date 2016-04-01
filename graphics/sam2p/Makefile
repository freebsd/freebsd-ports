# Created by: ijliao
# $FreeBSD$

PORTNAME=	sam2p
PORTVERSION=	0.49.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts raster (bitmap) image formats into PS or PDF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	zip:archivers/zip \
		tif22pnm:graphics/tif22pnm

USES=		ghostscript:run gmake jpeg:run perl5
USE_PERL5=	build
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_pts_bash="${SH}"
CONFIGURE_ARGS=	--enable-gif
MAKE_ARGS=	CXXX="${CXX}" LDALL="${CXX}" CXXFLAGSB="${CXXFLAGS}" CC="${CC}" CXX="${CXX}"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
