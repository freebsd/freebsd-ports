PORTNAME=	Tcl
PORTVERSION=	1.32
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tcl extension module for Perl5
WWW=		https://metacpan.org/release/Tcl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Devel-Refcount>0:devel/p5-Devel-Refcount

USES=		perl5 tcl
USE_PERL5=	configure

CONFIGURE_ARGS=	--nousestubs \
		--tclsh  ${TCLSH}
PORTSCOUT=	limit:^[0-9\.]*$$

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tcl/Tcl.so

.include <bsd.port.mk>
