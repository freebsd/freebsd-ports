# ex:ts=8
# Ports collection makefile for:	orsa
# Date created:			Dec 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	orsa
PORTVERSION=	0.6.2
PORTREVISION=	5
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Orbit Reconstruction, Simulation and Analysis

LIB_DEPENDS=	gsl.9:${PORTSDIR}/math/gsl \
		cln.4:${PORTSDIR}/math/cln \
		fftw.2:${PORTSDIR}/math/fftw \
		ginac-1.3.3:${PORTSDIR}/math/GiNaC

USE_QT_VER=	3
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
