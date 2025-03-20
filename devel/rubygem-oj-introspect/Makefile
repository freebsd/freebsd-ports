PORTNAME=	oj-introspect
PORTVERSION=	0.8.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Embeds start and end byte offsets of JSON objects
WWW=		https://github.com/meinac/oj-introspect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

MY_DEPENDS=	rubygem-oj>=3.16.10:devel/rubygem-oj
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		gem
#USES+=	ruby:extconf
#RUBY_EXTCONF_SUBDIRS=	ext/oj-introspect

.include <bsd.port.mk>
