# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	byebug
PORTVERSION=	2.7.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby 2 debugger

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	rubygem-columnize>=0.3:${PORTSDIR}/devel/rubygem-columnize \
		rubygem-debugger-linecache>=1.2:${PORTSDIR}/devel/rubygem-debugger-linecache

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/byebug

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
IGNORE=		Requires Ruby 2.0 or newer
.endif

.include <bsd.port.post.mk>
