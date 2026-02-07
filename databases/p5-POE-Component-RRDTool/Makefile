PORTNAME=	POE-Component-RRDTool
PORTVERSION=	0.18
PORTREVISION=	6
CATEGORIES=	databases perl5 devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TCAINE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE interface to Round Robin Database Tools
WWW=		https://metacpan.org/release/TCAINE/POE-Component-RRDTool-0.18

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	rrdtool:databases/rrdtool \
		p5-POE>=0:devel/p5-POE

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	</dev/null

post-patch:
	@${REINPLACE_CMD} -e 's|($$maj, $$min, $$sub)|&; &|' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 504200
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-Makefile.PL
.endif

.include <bsd.port.post.mk>
