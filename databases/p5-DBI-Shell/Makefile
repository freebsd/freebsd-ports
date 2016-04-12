# Created by: dcf@aracnet.com
# $FreeBSD$

PORTNAME=	DBI-Shell
PORTVERSION=	11.95
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interactive command shell for the DBI

RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Text-Reform>=0:textproc/p5-Text-Reform \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-IO-Tee>=0:devel/p5-IO-Tee
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	lib/DBI/Shell/SQLMinus.pm
perl_OLD_CMD=	perl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
