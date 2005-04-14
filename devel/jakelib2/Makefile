# ex:ts=8
# Ports collection makefile for:	jakelib2
# Date created:			Oct 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jakelib2
PORTVERSION=	2.0.0.s
CATEGORIES=	devel
MASTER_SITES=	http://www.jakelib.org/lib/jakelib2/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross platform C++ class library with a Java-like API

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-debug

INSTALLS_SHLIB=	yes
INFO=	jakelib2

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
