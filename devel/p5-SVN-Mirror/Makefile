PORTNAME=	SVN-Mirror
PORTVERSION=	0.75
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mirror remote subversion repository to local
WWW=		https://metacpan.org/release/SVN-Mirror

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-SVN-Simple>=0:devel/p5-SVN-Simple \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-URI>=0:net/p5-URI \
		p5-VCP-autrijus>=0:devel/p5-VCP-autrijus
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS+=	p5-subversion>=0:devel/p5-subversion
.endif

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
