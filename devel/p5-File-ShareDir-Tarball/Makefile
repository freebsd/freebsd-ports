PORTNAME=	File-ShareDir-Tarball
PORTVERSION=	0.2.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Deal transparently with shared files distributed as tarballs

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Module-Build>=0:devel/p5-Module-Build
RUN_DEPENDS=	p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-chdir>=0:devel/p5-File-chdir
TEST_DEPENDS=	p5-Test-File-ShareDir>=0.3.0:devel/p5-Test-File-ShareDir

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/File/ShareDir/Tarball.pm \
		${SITE_MAN3_REL}/File::ShareDir::Tarball.3.gz

.include <bsd.port.mk>
