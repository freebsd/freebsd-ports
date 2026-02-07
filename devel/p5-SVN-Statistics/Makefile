PORTNAME=	SVN-Statistics
PORTVERSION=	0.041
PORTREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LINMAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl module to generate Subversion statistics
WWW=		https://metacpan.org/release/LINMAR/SVN-Statistics-0.041

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion
.endif
RUN_DEPENDS+=	p5-RRDTool-OO>=0:devel/p5-RRDTool-OO \
		p5-Data-Dumper-Simple>=0:devel/p5-Data-Dumper-Simple \
		p5-IO-Toolkit>=0:devel/p5-IO-Toolkit

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
