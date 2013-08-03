# Created by: ijliao
# $FreeBSD$

PORTNAME=	sam2p
PORTVERSION=	0.49.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts raster (bitmap) image formats into PS or PDF files

LICENSE=	GPLv2

RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		cjpeg:${PORTSDIR}/graphics/jpeg \
		tif22pnm:${PORTSDIR}/graphics/tif22pnm

USES=		perl5
USE_PERL5=	build
USE_GHOSTSCRIPT_RUN=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_pts_bash="${SH}"
MAKE_ARGS=	CXXX="${CXX}" LDALL="${CXX}" CXXFLAGSB="${CXXFLAGS}"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	README
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
