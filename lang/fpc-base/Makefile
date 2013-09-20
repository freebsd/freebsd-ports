# Created by: John Merryweather Cooper <coop9211@uidaho.edu>
# $FreeBSD$

PORTNAME=	base
PORTVERSION=	2.6.2
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

NO_STAGE=	yes
.include <bsd.port.mk>
