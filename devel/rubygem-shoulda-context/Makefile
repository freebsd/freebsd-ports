# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shoulda-context
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Context framework extracted from Shoulda

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES+=	bin/convert_to_should_syntax

post-patch:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} g+rx '{}' +
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} g+r  '{}' +

.include <bsd.port.mk>
