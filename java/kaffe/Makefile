# New ports collection makefile for:    kaffe
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	kaffe
PORTVERSION=	1.0.7
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/v1.0.x-production/

MAINTAINER=	xaa+ports@timewasters.nl
COMMENT=	Multi-platform Java virtual machine including JIT compiler and AWT package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png

NOT_FOR_ARCHS=	amd64

USE_LIBTOOL=	yes
LIBTOOLFLAGS=
INSTALLS_SHLIB=	yes

PLIST_SUB+=	PORTVER=${PORTVERSION} ARCH=${ARCH}

MAN1=		kaffe.1

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/BUILD_ENVIRONMENT ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.terms ${DATADIR}

.include <bsd.port.mk>
