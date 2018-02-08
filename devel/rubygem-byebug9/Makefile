# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	byebug
PORTVERSION=	9.1.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG
PKGNAMESUFFIX=	9

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby 2 debugger

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use devel/rubygem-byebug instead
EXPIRATION_DATE=2018-02-28

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/byebug9
PORTSCOUT=	limit:^1\.

post-extract:
	@${MV} ${WRKSRC}/bin/byebug ${WRKSRC}/bin/byebug9

.include <bsd.port.mk>
