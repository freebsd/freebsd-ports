# ex:ts=8
# Ports collection makefile for:	orsa
# Date created:			Dec 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	orsa
PORTVERSION=	0.7.0
PORTREVISION=	18
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Orbit Reconstruction, Simulation and Analysis

LIB_DEPENDS=	gsl.15:${PORTSDIR}/math/gsl \
		cln.6:${PORTSDIR}/math/cln \
		fftw.2:${PORTSDIR}/math/fftw \
		ginac-1.5.2:${PORTSDIR}/math/GiNaC

USE_QT_VER=	3
USE_GL=		gl
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
ACLOCAL_ARGS=	-I macros -I ${LOCALBASE}/share/aclocal
CONFIGURE_ENV=	ac_cv_c_inline=no
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.include <bsd.port.post.mk>
