# New ports collection makefile for:	taxipilot
# Date created:				2003-07-03
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	taxipilot
PORTVERSION=	0.8.5
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	taxipilot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Spacetaxi clone

LIB_DEPENDS=	noatun.0:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500028
BROKEN=		"Does not build on 4.x"
.endif

.include <bsd.port.post.mk>
