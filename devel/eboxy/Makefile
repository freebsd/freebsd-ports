# ex:ts=8
# Ports collection makefile for:	eboxy
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eboxy
PORTVERSION=	0.3.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create simple GUI interfaces for entertainment PC

USE_SDL=	sdl gui
USE_GNOME=	gnometarget libxml2
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-lirc

MAN1=		eboxy.1

CPPFLAGS=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include \
		-DHAVE_DECL_GETOPT
LDFLAGS=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 $$CFLAGS|$$CFLAGS|g' ${WRKSRC}/configure
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
