# $FreeBSD$

PORTNAME=	ruby-xz
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for the liblzma library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-ffi>=1.9:devel/rubygem-ffi \
		rubygem-io-like>=0.3:devel/rubygem-io-like \
		rubygem-archive-tar-minitar>=0.5:archivers/rubygem-archive-tar-minitar

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
