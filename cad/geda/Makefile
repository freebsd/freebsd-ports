# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	20060123
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	The "meta-port" for gEDA

RUN_DEPENDS=	${LOCALBASE}/share/gEDA/sym:${PORTSDIR}/cad/geda-symbols \
		gschem:${PORTSDIR}/cad/gschem \
		gnetlist:${PORTSDIR}/cad/gnetlist \
		gmk_sym:${PORTSDIR}/cad/geda-utils \
		gsymcheck:${PORTSDIR}/cad/geda-symcheck \
		gattrib:${PORTSDIR}/cad/geda-gattrib \
		geda:${PORTSDIR}/cad/geda-projectmanager

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
