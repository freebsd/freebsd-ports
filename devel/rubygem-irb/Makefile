# $FreeBSD$

PORTNAME=	irb
PORTVERSION=	1.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Interactive Ruby

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-reline>=0.0.1:devel/rubygem-reline

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 2.6
IGNORE=		irb is included in lang/${RUBY_NAME}
.endif

# irb executable is installed by ruby port
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/irb

.include <bsd.port.post.mk>
