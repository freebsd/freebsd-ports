PORTNAME=	graphql-docs
PORTVERSION=	4.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generate beautiful documentation from your GraphQL schema
WWW=		https://github.com/gjtorikian/graphql-docs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-commonmarker>=0.23.6<1:textproc/rubygem-commonmarker \
		rubygem-dartsass>=1.49<2:textproc/rubygem-dartsass \
		rubygem-escape_utils>=1.2<2.0:textproc/rubygem-escape_utils \
		rubygem-extended-markdown-filter>=0.4<1.0:textproc/rubygem-extended-markdown-filter \
		rubygem-gemoji3>=3.0<4.0:textproc/rubygem-gemoji3 \
		rubygem-graphql>=2.0<3.0:devel/rubygem-graphql \
		rubygem-html-pipeline>=2.14.3<3.0:textproc/rubygem-html-pipeline

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/graphql-docs

.include <bsd.port.mk>
