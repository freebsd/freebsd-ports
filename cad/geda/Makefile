# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	20030223
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	The "meta-port" for gEDA

BUILD_DEPENDS=	gesym-config:${PORTSDIR}/cad/geda-symbols \
		gschem:${PORTSDIR}/cad/gschem \
		gnetlist:${PORTSDIR}/cad/gnetlist \
		gmk_sym:${PORTSDIR}/cad/geda-utils \
		gsymcheck:${PORTSDIR}/cad/geda-symcheck

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile \
		geda.18:${PORTSDIR}/cad/libgeda

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
