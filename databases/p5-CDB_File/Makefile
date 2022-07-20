PORTNAME=	CDB_File
PORTVERSION=	1.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nistor@snickers.org
COMMENT=	Perl5 interface to the CDB package

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	bun-x.pl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CDB_File/CDB_File.so

.include <bsd.port.mk>
