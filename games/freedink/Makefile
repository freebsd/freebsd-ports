# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedink
PORTVERSION=	108.4
CATEGORIES=	games

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Metaport for FreeDink engine and data

RUN_DEPENDS=	freedink-engine>=${PORTVERSION}:games/freedink-engine \
		freedink-data>=1.08.20140901:games/freedink-data \
		freedink-dfarc>=3.12:games/freedink-dfarc

USES=		metaport

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"

.include <bsd.port.mk>
