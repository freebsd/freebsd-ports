# New ports collection makefile for:	acorn
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	acorn
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=   # empty
DISTFILES=      # empty

MAINTAINER=	lehmann@ans-netz.de

RUN_DEPENDS=	${PREFIX}/include/Atlas:${PORTSDIR}/devel/atlas \
		${PREFIX}/include/uta:${PORTSDIR}/devel/libuta \
		${PREFIX}/include/varconf:${PORTSDIR}/devel/varconf \
		${PREFIX}/share/forge/media:${PORTSDIR}/games/acorn-media \
		${PREFIX}/bin/uclient:${PORTSDIR}/games/uclient

EXTRACT_ONLY=   # empty
NO_BUILD=       yes

do-install:     # empty

.include <bsd.port.mk>
