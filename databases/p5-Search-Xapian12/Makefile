# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Search-Xapian
PORTVERSION=	1.2.25.2
CATEGORIES=	databases perl5
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION:R}/ \
		LOCAL/sunpoet \
		CPAN
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libxapian.so:databases/xapian-core12
TEST_DEPENDS=	p5-Devel-Leak>=0:devel/p5-Devel-Leak \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

CC=		${CXX}
CONFIGURE_ARGS=	XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config

# later version does not support xapian-core 1.2.x
PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e 's|^if (defined $$builddir) {|if (0) {|' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Search/Xapian/Xapian.so

.include <bsd.port.mk>
