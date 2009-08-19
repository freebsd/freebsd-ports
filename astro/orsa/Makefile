# ex:ts=8
# Ports collection makefile for:	orsa
# Date created:			Dec 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	orsa
PORTVERSION=	0.7.0
PORTREVISION=	10
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Orbit Reconstruction, Simulation and Analysis

LIB_DEPENDS=	gsl.13:${PORTSDIR}/math/gsl \
		cln.6:${PORTSDIR}/math/cln \
		fftw.2:${PORTSDIR}/math/fftw \
		ginac-1.5.3:${PORTSDIR}/math/GiNaC

USE_QT_VER=	3
USE_GL=		gl
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I macros -I ${LOCALBASE}/share/aclocal
CONFIGURE_ENV=	ac_cv_c_inline=no
USE_LDCONFIG=	yes

.include <bsd.port.mk>
