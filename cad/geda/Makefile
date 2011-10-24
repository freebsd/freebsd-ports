# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	1.4.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "meta-port" for gEDA

RUN_DEPENDS=	${DATADIR}/sym:${PORTSDIR}/cad/geda-symbols \
		gschem:${PORTSDIR}/cad/geda-gschem \
		gnetlist:${PORTSDIR}/cad/geda-netlist \
		gmk_sym:${PORTSDIR}/cad/geda-utils \
		gsymcheck:${PORTSDIR}/cad/geda-symcheck \
		gattrib:${PORTSDIR}/cad/geda-gattrib

NO_BUILD=	yes

OPTIONS=	EXAMPLES	"Install gEDA's examples"	on \
		DOCS		"Install gEDA's documentation"	on

.if !defined(WITHOUT_EXAMPLES)
RUN_DEPENDS+=	${EXAMPLESDIR}/README:${PORTSDIR}/cad/geda-examples
.endif

.if !defined(WITHOUT_DOCS)
RUN_DEPENDS+=	${DOCSDIR}/gedadocs.html:${PORTSDIR}/cad/geda-docs
.endif

do-install:	# empty

.include <bsd.port.mk>
