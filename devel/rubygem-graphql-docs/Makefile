PORTNAME=	graphql-docs
PORTVERSION=	1.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generate beautiful documentation from your GraphQL schema

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-commonmarker>=0.16<2.0:textproc/rubygem-commonmarker \
		rubygem-escape_utils>=1.2<2.0:textproc/rubygem-escape_utils \
		rubygem-extended-markdown-filter>=0.4<1.0:textproc/rubygem-extended-markdown-filter \
		rubygem-gemoji>=3.0<4.0:textproc/rubygem-gemoji \
		rubygem-graphql>=1.6<2.0:devel/rubygem-graphql \
		rubygem-html-pipeline>=2.9<3.0:textproc/rubygem-html-pipeline \
		rubygem-sass>=3.4<4.0:textproc/rubygem-sass

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
