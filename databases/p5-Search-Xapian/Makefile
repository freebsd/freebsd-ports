# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>

PORTNAME=	Search-Xapian
PORTVERSION=	1.2.25.5
CATEGORIES=	databases perl5
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION:R}/ \
		LOCAL/sunpoet \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libxapian.so:databases/xapian-core
TEST_DEPENDS=	p5-Devel-Leak>=0:devel/p5-Devel-Leak \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

CC=		${CXX}
CONFIGURE_ARGS=	XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config

CONFLICTS_INSTALL=	p5-Search-Xapian12 # lib/perl5/site_perl/mach/5.32/Search/Xapian.pm

post-patch:
	@${REINPLACE_CMD} -e 's|^if (defined $$builddir) {|if (0) {|' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Search/Xapian/Xapian.so

.include <bsd.port.mk>
