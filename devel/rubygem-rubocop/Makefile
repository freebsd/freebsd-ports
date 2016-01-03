# $FreeBSD$

PORTNAME=	rubocop
PORTVERSION=	0.35.1
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby code style checking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-astrolabe>=1.3:${PORTSDIR}/devel/rubygem-astrolabe \
		rubygem-parser>=2.2.3.0:${PORTSDIR}/devel/rubygem-parser \
		rubygem-powerpack>=0.1:${PORTSDIR}/devel/rubygem-powerpack \
		rubygem-rainbow>=1.99.1:${PORTSDIR}/devel/rubygem-rainbow \
		rubygem-ruby-progressbar>=1.7:${PORTSDIR}/devel/rubygem-ruby-progressbar \
		rubygem-tins>=0:${PORTSDIR}/devel/rubygem-tins

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rubocop

.include <bsd.port.mk>
