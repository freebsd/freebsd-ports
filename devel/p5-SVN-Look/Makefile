PORTNAME=	SVN-Look
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Caching wrapper around the svnlook command
WWW=		https://metacpan.org/release/SVN-Look

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-XML-Simple>=0:textproc/p5-XML-Simple
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	subversion-lts>0:devel/subversion-lts
.else
RUN_DEPENDS+=	subversion>0:devel/subversion
.endif

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
