# New ports collection makefile for:	kpacman
# Date created:				Wed May 14 2003
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpacman
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kpacman

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Pacman Clone for KDE

LIB_DEPENDS=	kdegames.2:${PORTSDIR}/games/kdegames3

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	${REINPLACE_CMD} -e "s,-lqt,-lqt-mt ${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
