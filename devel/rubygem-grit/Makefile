# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	grit
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-oriented ruby library to access git repositories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-diff-lcs>=1.1<2:textproc/rubygem-diff-lcs \
		rubygem-mime-types1>=1.15<2:misc/rubygem-mime-types1 \
		rubygem-posix-spawn>=0.3.6<0.4:devel/rubygem-posix-spawn

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
