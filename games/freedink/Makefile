# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedink
PORTVERSION=	108.4
CATEGORIES=	games
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Metaport for FreeDink engine and data

RUN_DEPENDS=	freedink>=${PORTVERSION}:${PORTSDIR}/games/freedink-engine \
		freedink-data>=1.08.20140901:${PORTSDIR}/games/freedink-data \
		dfarc>=3.12:${PORTSDIR}/games/freedink-dfarc

NO_BUILD=	yes

do-install:	# empty

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"

.include <bsd.port.mk>
