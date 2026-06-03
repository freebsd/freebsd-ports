PORTNAME=	ExtUtils-ParseXS
PORTVERSION=	3.61
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Converts Perl XS code into C code
WWW=		https://metacpan.org/release/ExtUtils-ParseXS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	lib/ExtUtils/xsubpp
# Overwrite this here
perl_OLD_CMD=	perl
SHEBANG_FILES=	lib/ExtUtils/xsubpp

post-patch:
	@${REINPLACE_CMD} '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
