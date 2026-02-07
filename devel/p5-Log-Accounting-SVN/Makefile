PORTNAME=	Log-Accounting-SVN
PORTVERSION=	0.01
PORTREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl module for accounting SVN repository
WWW=		https://metacpan.org/release/GUGOD/Log-Accounting-SVN-0.01

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion
.endif
RUN_DEPENDS+=	p5-SVN-Log>=0:devel/p5-SVN-Log \
		p5-Algorithm-Accounting>=0:devel/p5-Algorithm-Accounting \
		p5-Test-Simple>=0:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
