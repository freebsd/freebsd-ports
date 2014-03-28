# Created by: John Merryweather Cooper <coop9211@uidaho.edu>
# $FreeBSD$

PORTNAME=	base
PORTVERSION=	2.6.4
CATEGORIES=	lang
MASTER_SITES=	# empty
PKGNAMEPREFIX=	fpc-
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Meta package to install all of the Free Pascal base

WANT_FPC_BASE=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	DOCS

DOCS_RUN_DEPENDS=	${LOCALBASE}/share/doc/fpdocs-${PORTVERSION}/user.pdf:${PORTSDIR}/lang/fpc-docs

.include <bsd.port.mk>
