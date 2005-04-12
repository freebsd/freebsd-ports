# New ports collection makefile for:	kpictorial
# Date created:				2003-10-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpictorial
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kpictorial

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Little logical game for KDE

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=		yes
USE_REINPLACE=		yes

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
