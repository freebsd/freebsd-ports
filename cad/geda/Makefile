# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	20010304
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	bruno@tinkerbox.org

BUILD_DEPENDS=	gesym-config:${PORTSDIR}/cad/geda-symbols \
		gschem:${PORTSDIR}/cad/gschem \
		gnetlist:${PORTSDIR}/cad/gnetlist
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile \
		geda.12:${PORTSDIR}/cad/libgeda

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
