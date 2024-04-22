PORTNAME=	Lock-File
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MMCLERIC
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	File locker with an automatic out-of-scope unlocking mechanism
WWW=		https://metacpan.org/release/Lock-File

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Log-Any>0:devel/p5-Log-Any
TEST_DEPENDS=	p5-IPC-System-Simple>0:devel/p5-IPC-System-Simple \
		p5-Test-Class>0:devel/p5-Test-Class \
		p5-Test-Fatal>0:devel/p5-Test-Fatal \
		p5-Test-Warn>0:devel/p5-Test-Warn
#RELEASE TEST#	p5-Pod-Coverage-TrustPod>0:devel/p5-Pod-Coverage-TrustPod
#RELEASE TEST#	p5-Test-Pod>0:devel/p5-Test-Pod
#RELEASE TEST#	p5-Test-Pod-Coverage>0:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

TEST_ENV=	# RELEASE_TESTING=1 #: release test not work #

NO_ARCH=	yes

PLIST_FILES=	${SITE_MAN3_REL}/Lock::File.3.gz \
		${SITE_MAN3_REL}/Lock::File::Alarm.3.gz \
		${SITE_PERL_REL}/Lock/File.pm \
		${SITE_PERL_REL}/Lock/File/Alarm.pm

.include <bsd.port.mk>
