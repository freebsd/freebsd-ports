# Created by: dcf@aracnet.com
# $FreeBSD$

PORTNAME=	DBI-Shell
PORTVERSION=	11.96
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interactive command shell for the DBI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-IO-Interactive>=0:devel/p5-IO-Interactive \
		p5-IO-Tee>=0:devel/p5-IO-Tee \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-Text-Reform>=0:textproc/p5-Text-Reform

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	lib/DBI/Shell/SQLMinus.pm
perl_OLD_CMD=	perl

.include <bsd.port.mk>
