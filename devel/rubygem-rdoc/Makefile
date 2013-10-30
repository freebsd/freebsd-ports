# $FreeBSD$

PORTNAME=	rdoc
PORTVERSION=	3.12.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects

BUILD_DEPENDS=	rubygem-json>=1.4:${PORTSDIR}/devel/rubygem-json
RUN_DEPENDS=	rubygem-json>=1.4:${PORTSDIR}/devel/rubygem-json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RUBY_FEATURES=	iconv
RUBYGEM_AUTOPLIST=	yes

GEM_ENV+=	RUBYLIB=${PREFIX}/${GEM_LIB_DIR}/lib

.include <bsd.port.pre.mk>

pre-install:
RUBYGEM_ARGS+=	--bindir ${WRKDIR}

.include <bsd.port.post.mk>
