PORTNAME=	Glib-Object-Introspection
PORTVERSION=	0.051
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dynamically create Perl language bindings
WWW=		https://metacpan.org/release/Glib-Object-Introspection

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.300:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:devel/p5-ExtUtils-PkgConfig \
		${RUN_DEPENDS}
LIB_DEPENDS=	libffi.so:devel/libffi
RUN_DEPENDS=	p5-Glib>=1.320:devel/p5-Glib
TEST_DEPENDS=	p5-Cairo-GObject>=0:devel/p5-Cairo-GObject

USES=		gnome perl5
USE_GNOME=	introspection
USE_PERL5=	configure

OPTIONS_DEFINE=	TEST

# It requires cairo to build test libraries during build phase
TEST_BUILD_DEPENDS=	cairo>=0:graphics/cairo

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Glib/Object/Introspection/Introspection.so

.include <bsd.port.mk>
