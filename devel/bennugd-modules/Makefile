# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	modules
PORTVERSION=	r20091106
PORTREVISION=	4
CATEGORIES=	devel games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	bennugd-
DISTNAME=	bennugd-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High level open source game development suite, modules

BUILD_DEPENDS=	${LOCALBASE}/lib/libbgdrtm.so:${PORTSDIR}/devel/bennugd-core
RUN_DEPENDS=	${LOCALBASE}/lib/libbgdrtm.so:${PORTSDIR}/devel/bennugd-core
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--libdir="${PREFIX}/lib/bennugd"
MAKE_JOBS_SAFE=	yes

USE_DOS2UNIX=	*.c

WRKSRC=		${WRKDIR}/bennugd/${PORTNAME}

post-extract:
	@${CHMOD} a+x ${WRKSRC}/configure ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
