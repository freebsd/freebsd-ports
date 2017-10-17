# Created by: Jon Nistor <nistor@snickers.org>
# $FreeBSD$

PORTNAME=	CDB_File
PORTVERSION=	0.99
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nistor@snickers.org
COMMENT=	Perl5 interface to the CDB package

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
SHEBANG_FILES=	bun-x.pl
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CDB_File/CDB_File.so

.include <bsd.port.mk>
