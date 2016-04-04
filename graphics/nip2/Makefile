# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nip2
PORTVERSION=	8.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Graphical user interface for VIPS

LICENSE=	GPLv2

BUILD_DEPENDS=	xdg-open:devel/xdg-utils
LIB_DEPENDS=	libvips.so:graphics/vips
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		bison desktop-file-utils dos2unix gettext gmake pkgconfig \
		shared-mime-info
DOS2UNIX_GLOB=	*.def
USE_GNOME=	gnomemimedata gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-desktop
LDFLAGS+=	-lm

SUB_FILES=	run-nip2.sh

OPTIONS_DEFINE=		DOCS FFTW GOFFICE GRAPHVIZ GSF GSL
OPTIONS_DEFAULT=	FFTW GOFFICE GRAPHVIZ GSF GSL

FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_CONFIGURE_WITH=	fftw3
GOFFICE_DESC=		Use libgoffice to show plots
GOFFICE_LIB_DEPENDS=	libgoffice-*.so:devel/goffice
GOFFICE_CONFIGURE_WITH=	libgoffice
GRAPHVIZ_DESC=		Use libgvc to show workspace dependency graphs
GRAPHVIZ_LIB_DEPENDS=	libgvc.so:graphics/graphviz
GRAPHVIZ_CONFIGURE_WITH=	libgvc
GSF_DESC=		Use libgsf to save plots to files
GSF_USE=		gnome=libgsf
GSF_CONFIGURE_WITH=	libgsf
GSL_DESC=		Use gsl for numeric functions
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_WITH=	gsl

post-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} run-nip2.sh \
		${STAGEDIR}/${PREFIX}/bin)

test check: build
	#
	# Checks currently require ImageMagick's convert to be available
	# and aren't enabled by default. They take a long time -- tail
	# the log-file:
	#	${WRKSRC}/test/test_all.sh.log
	#
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
