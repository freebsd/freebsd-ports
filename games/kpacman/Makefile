# New ports collection makefile for:	kpacman
# Date created:				Wed May 14 2003
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpacman
PORTVERSION=	0.3.1
CATEGORIES=	games kde
MASTER_SITES=	http://www.mat.univie.ac.at/~martin/
DISTNAME=	${PORTNAME}-${PORTVERSION}-kde3

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Pacman Clone for KDE

USE_KDELIBS=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	${REINPLACE_CMD} -e "s,-lqt,-lqt-mt ${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
