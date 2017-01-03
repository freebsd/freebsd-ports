# $FreeBSD$

PORTNAME=	rdoc
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.rdoc

RUN_DEPENDS=	rubygem-json1>=1.4:devel/rubygem-json1

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rdoc ${STAGEDIR}${PREFIX}/bin/ri

DEPRECATED=	Older version no longer required
EXPIRATION_DATE=	2017-01-08

.include <bsd.port.mk>
