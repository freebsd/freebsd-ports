# ex:ts=8
# New ports collection makefile for:	jakelib2
# Date created:			Oct 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jakelib2
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.donuz.de/lib/jakelib2/download/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A cross platform C++ class library with a Java-like API

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-debug

USE_LDCONFIG=	yes
INFO=		jakelib2

PORTSCOUT=	limit:2.0.3

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure
# Fixes for GCC 4.2
	@${REINPLACE_CMD} -e '178s|gc::||' \
		${WRKSRC}/include/jakelib2/gc/gc_cpp.h
	@${REINPLACE_CMD} -e 's|SimpleDateFormat::||' \
		${WRKSRC}/include/jakelib2/text/SimpleDateFormat.h

.include <bsd.port.mk>
