# New ports collection makefile for:	burgerspace
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	burgerspace
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www3.sympatico.ca/sarrazip/dev/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A BurgerTime clone

LIB_DEPENDS=	gengameng.4:${PORTSDIR}/devel/gengameng

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CPPFLAGS=	-I${X11BASE}/include -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CCONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-gengameng-prefix="${X11BASE}"

MAN6=		burgerspace.6
PLIST_FILES=	bin/burgerspace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/burgerspace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/burgerspace.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
