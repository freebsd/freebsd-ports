# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	20060123
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	The "meta-port" for gEDA

RUN_DEPENDS=	${DATADIR}/sym:${PORTSDIR}/cad/geda-symbols \
		gschem:${PORTSDIR}/cad/geda-gschem \
		gnetlist:${PORTSDIR}/cad/geda-netlist \
		gmk_sym:${PORTSDIR}/cad/geda-utils \
		gsymcheck:${PORTSDIR}/cad/geda-symcheck \
		gattrib:${PORTSDIR}/cad/geda-gattrib \
		geda:${PORTSDIR}/cad/geda-projectmanager

NO_BUILD=	yes

OPTIONS=	EXAMPLES	"Install gEDA's examples"	on \
		DOCS		"Install gEDA's documentation"	on

.if !defined(WITHOUT_EXAMPLES)
RUN_DEPENDS+=	${EXAMPLESDIR}/README:${PORTSDIR}/cad/geda-examples
.endif

.if !defined(WITHOUT_DOCS)
RUN_DEPENDS+=	${DOCSDIR}/attributes/index.html:${PORTSDIR}/cad/geda-docs
.endif

do-install:	# empty

.include <bsd.port.mk>
