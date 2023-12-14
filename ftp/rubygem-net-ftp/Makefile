PORTNAME=	net-ftp
PORTVERSION=	0.3.0
CATEGORIES=	ftp rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Support for the File Transfer Protocol
WWW=		https://github.com/ruby/net-ftp

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-net-protocol>=0:net/rubygem-net-protocol \
		rubygem-time>=0:devel/rubygem-time

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
