# New ports collection makefile for:	fpc-base
# Date created:				10 February 2004
# Whom:				John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	# empty
PKGNAMEPREFIX=	fpc-
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Meta package to install all of the Free Pascal base

WANT_FPC_BASE=	yes

.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	${LOCALBASE}/share/doc/fpdocs-${PORTVERSION}/user.pdf:${PORTSDIR}/lang/fpc-docs
.endif

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
