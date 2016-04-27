# $FreeBSD$

PORTNAME=	rdoc
PORTVERSION=	3.12.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.rdoc

RUN_DEPENDS=	rubygem-json>=1.4:devel/rubygem-json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rdoc ${STAGEDIR}${PREFIX}/bin/ri

.include <bsd.port.mk>
