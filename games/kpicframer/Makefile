# New ports collection Makefile for:	kpicframer
# Date created:				2004-01-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpicframer
PORTVERSION=	0.5
CATEGORIES=	games kde
MASTER_SITES=	http://www.norbs.de/kpicframer/download/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	KDE card game

BUILD_DEPENDS=	autoconf257:${PORTSDIR}/devel/autoconf257 \
		automake17:${PORTSDIR}/devel/automake17

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-configure:
	cd ${WRKSRC}; ${MAKE} -f admin/Makefile.common cvs
	${FIND} ${WRKSRC} -name "*.ui" | ${XARGS} ${REINPLACE_CMD} -e "s,version=\"3.3\",version=\"3.2\","

pre-build:
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
