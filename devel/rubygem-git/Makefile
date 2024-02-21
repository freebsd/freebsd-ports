PORTNAME=	git
PORTVERSION=	1.19.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby wrapper library around git(1)
WWW=		https://github.com/ruby-git/ruby-git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git>=1.6:devel/git \
		rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-rchardet>=1.8<2:textproc/rubygem-rchardet

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
