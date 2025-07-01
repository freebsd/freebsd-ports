PORTNAME=	Sys-Virt
PORTVERSION=	11.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DANBERR
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Perl bindings for libvirt
WWW=		https://metacpan.org/release/Sys-Virt

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build>=0:devel/p5-Module-Build \
		p5-XML-XPath>=0:textproc/p5-XML-XPath
LIB_DEPENDS=	libvirt.so:devel/libvirt
RUN_DEPENDS=	p5-XML-XPath>=0:textproc/p5-XML-XPath
TEST_DEPENDS=	p5-CPAN-Changes>=0:devel/p5-CPAN-Changes \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

USES=		perl5 pkgconfig shebangfix
SHEBANG_FILES=	examples/*.pl
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sys/Virt/Virt.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
