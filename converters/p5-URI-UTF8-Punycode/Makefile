# Created by: Timur Bakeyev <bat@cpan.org>
# $FreeBSD$

PORTNAME=	URI-UTF8-Punycode
PORTVERSION=	1.05
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Punycode conversion of UTF-8 string

LICENSE=	GPLv3

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_ARCH}/auto/URI/UTF8/Punycode/Punycode.so

.include <bsd.port.mk>
