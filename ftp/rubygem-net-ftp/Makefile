# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	net-ftp
PORTVERSION=	0.1.2
CATEGORIES=	ftp rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Support for the File Transfer Protocol

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-net-protocol>=0:net/rubygem-net-protocol \
		rubygem-time>=0:devel/rubygem-time

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
