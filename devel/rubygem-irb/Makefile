# $FreeBSD$

PORTNAME=	irb
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Interactive Ruby

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# irb executable is installed by ruby port
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/irb

.include <bsd.port.mk>
