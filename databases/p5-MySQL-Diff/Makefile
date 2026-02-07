PORTNAME=	MySQL-Diff
PORTVERSION=	0.50
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl module for comparing the table structure of two MySQL databases
WWW=		https://metacpan.org/release/MySQL-Diff

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-MakeMethods>=0:devel/p5-Class-MakeMethods \
		${DBD_MYSQL} \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote

USES=		mysql perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	bin/mysqldiff

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mysqldiff ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
