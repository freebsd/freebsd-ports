# New ports collection makefile for:	kpovmodeler
# Date created:		24 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kpovmodeler
PORTVERSION=	0.2
CATEGORIES=	graphics kde
MASTER_SITES=	http://www.uni-ulm.de/~s_azehen/

MAINTAINER=	stefan.jahn@nemesis-sektor.de

RUN_DEPENDS=    povray:${PORTSDIR}/graphics/povray31

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
