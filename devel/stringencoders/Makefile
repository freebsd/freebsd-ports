# Created by: Steven Kreuzer <skreuzer@exit2shell.com>
# $FreeBSD$

PORTNAME=	stringencoders
PORTVERSION=	3.10.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of high performance c-string transformations

USES=		libtool perl5
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

BROKEN_powerpc=	Does not compile on powerpc

.include <bsd.port.mk>
