# Created by: John Merryweather Cooper <coop9211@uidaho.edu>
# $FreeBSD$

PORTNAME=	base
PORTVERSION=	3.0.2
CATEGORIES=	lang
PKGNAMEPREFIX=	fpc-

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Meta package to install all of the Free Pascal base

USES=		metaport
USE_FPC_RUN=	yes
WANT_FPC_BASE=	yes

OPTIONS_DEFINE=	DOCS

DOCS_RUN_DEPENDS=	${LOCALBASE}/share/doc/fpdocs-${PORTVERSION}/user.pdf:lang/fpc-docs

.include <bsd.port.mk>
