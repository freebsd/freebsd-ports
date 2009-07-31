# New ports collection makefile for:	afternoonstalker
# Date created:			Feb 15, 2003
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	afternoonstalker
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www3.sympatico.ca/sarrazip/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the 1981 Night Stalker video game

LIB_DEPENDS=	gengameng.4:${PORTSDIR}/devel/gengameng \
		flatzebra-0.1.2:${PORTSDIR}/devel/flatzebra

USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		afternoonstalker.6

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} "s@sounds/..PACKAGE.@afternoonstalker/sounds@g" \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
