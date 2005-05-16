# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	20050313
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	The "meta-port" for gEDA

RUN_DEPENDS=	${LOCALBASE}/share/gEDA/sym:${PORTSDIR}/cad/geda-symbols \
		gschem:${PORTSDIR}/cad/gschem \
		gnetlist:${PORTSDIR}/cad/gnetlist \
		gmk_sym:${PORTSDIR}/cad/geda-utils \
		gsymcheck:${PORTSDIR}/cad/geda-symcheck

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
