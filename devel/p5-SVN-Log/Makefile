PORTNAME=	SVN-Log
PORTVERSION=	0.03
PORTREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Extract change logs from Subversion server
WWW=		https://metacpan.org/release/SVN-Log

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion
.endif
RUN_DEPENDS+=	p5-Test-Simple>=0:devel/p5-Test-Simple

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
