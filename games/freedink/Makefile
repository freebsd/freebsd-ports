# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedink
PORTVERSION=	1.08.${PORTVER}
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Metaport for FreeDink engine and data

RUN_DEPENDS=	freedink:${PORTSDIR}/games/freedink-engine \
		freedink-data>0:${PORTSDIR}/games/freedink-data \
		dfarc:${PORTSDIR}/games/freedink-dfarc

NO_BUILD=	yes
PORTVER=	20121209

do-install:	# empty

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"
	@${ECHO_MSG} "This port does not ensure things are upgraded; use portupgrade if you want to"
	@${ECHO_MSG} "upgrade FreeDink."

.include <bsd.port.mk>
