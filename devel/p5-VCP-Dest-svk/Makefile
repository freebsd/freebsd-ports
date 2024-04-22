PORTNAME=	VCP-Dest-svk
PORTVERSION=	0.29
PORTREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	VCP destination driver for svn/svk
WWW=		https://metacpan.org/release/CLKAO/VCP-Dest-svk-0.29

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-VCP-autrijus>=0:devel/p5-VCP-autrijus \
		p5-YAML>=0:textproc/p5-YAML \
		svk>=0:devel/svk
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS+=	p5-subversion>=0:devel/p5-subversion
.endif

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
