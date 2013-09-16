# New ports collection makefile for:	stringencoders
# Date created:        11 June 2007
# Whom:                Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	stringencoders
PORTVERSION=	3.10.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of high performance c-string transformations

USES=		perl5
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
