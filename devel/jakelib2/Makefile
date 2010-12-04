# ex:ts=8
# New ports collection makefile for:	jakelib2
# Date created:			Oct 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jakelib2
PORTVERSION=	2.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.donuz.de/download/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A cross platform C++ class library with a Java-like API

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-debug

USE_LDCONFIG=	yes
INFO=		jakelib2

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
