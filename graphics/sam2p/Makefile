# Created by: ijliao
# $FreeBSD$

PORTNAME=	sam2p
PORTVERSION=	0.49.3
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	des@FreeBSD.org
COMMENT=	Converts raster (bitmap) image formats into PS or PDF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	zip:archivers/zip \
		tif22pnm:graphics/tif22pnm

BROKEN_aarch64=		running make Makedep... error; configure: error: cannot compute depends
BROKEN_armv6=		running make Makedep... error; configure: error: cannot compute depends
BROKEN_armv7=		running make Makedep... error; configure: error: cannot compute depends

#USE_GITHUB=	yes
GH_ACCOUNT=	pts

USES=		ghostscript:run gmake jpeg:run perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_pts_bash="${SH}"
CONFIGURE_ARGS=	--enable-gif
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
