PORTNAME=	Data-Sah
PORTVERSION=	0.917
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and featureful data structure validation
WWW=		https://metacpan.org/dist/Data-Sah

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Cmp>=0.002:devel/p5-Data-Cmp \
		p5-Data-Dmp>=0.242:devel/p5-Data-Dmp \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Data-Sah-Coerce>=0.050:devel/p5-Data-Sah-Coerce \
		p5-Data-Sah-DefaultValue>=0.005:devel/p5-Data-Sah-DefaultValue \
		p5-Data-Sah-Filter>=0.024:devel/p5-Data-Sah-Filter \
		p5-Data-Sah-Normalize>=0.051:devel/p5-Data-Sah-Normalize \
		p5-Data-Sah-Resolve>=0.010:devel/p5-Data-Sah-Resolve \
		p5-File-ShareDir-Tarball>=0:devel/p5-File-ShareDir-Tarball \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-JSON>=0:converters/p5-JSON \
		p5-Language-Expr>=0.29:devel/p5-Language-Expr \
		p5-Lingua-EN-Numbers-Ordinate>=1.02:textproc/p5-Lingua-EN-Numbers-Ordinate \
		p5-Log-ger>=0.038:devel/p5-Log-ger \
		p5-Mo>=0,1:devel/p5-Mo \
		p5-Module-Installed-Tiny>=0.011:devel/p5-Module-Installed-Tiny \
		p5-Regexp-Stringify>=0:devel/p5-Regexp-Stringify \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Scalar-Util-Numeric-PP>=0:devel/p5-Scalar-Util-Numeric-PP \
		p5-Text-sprintfn>=0:textproc/p5-Text-sprintfn \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash
TEST_DEPENDS=	p5-Sah>=0.9.50:devel/p5-Sah \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Time-Duration-Parse-AsHash>=0:devel/p5-Time-Duration-Parse-AsHash \
		p5-lib-filter>=0.03:devel/p5-lib-filter

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
