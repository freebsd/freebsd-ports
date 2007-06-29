# ex:ts=8
# Ports collection makefile for:	orsa
# Date created:			Dec 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	orsa
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Orbit Reconstruction, Simulation and Analysis

LIB_DEPENDS=	gsl.10:${PORTSDIR}/math/gsl \
		cln.4:${PORTSDIR}/math/cln \
		fftw.2:${PORTSDIR}/math/fftw \
		ginac-1.3.3:${PORTSDIR}/math/GiNaC

USE_AUTOTOOLS=	libtool:15
USE_QT_VER=	3
USE_GL=		gl
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,Body::,,' \
		${WRKSRC}/src/liborsa/orsa_body.h
	@${REINPLACE_CMD} -E 's,[[:alnum:]]+::(compare\(),\1,' \
		${WRKSRC}/src/libxorsa/xorsa_analysis.h \
		${WRKSRC}/src/libxorsa/xorsa_import_astorb_objects.h \
		${WRKSRC}/src/libxorsa/xorsa_object_selector.cc \
		${WRKSRC}/src/orsa/xorsa.h
	@${REINPLACE_CMD} -e 's,^extern,& "C",' \
		${WRKSRC}/src/libxorsa/xorsa_plot_area.h
	@${REINPLACE_CMD} -e '/nprintf/s,std::,,' \
		${WRKSRC}/src/libxorsa/xorsa_wrapper.cc

.include <bsd.port.mk>
