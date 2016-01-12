# Created by: ijliao
# $FreeBSD$

PORTNAME=	ppl
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/${PORTVERSION}/ \
		http://bugseng.com/products/ppl/download/ftp/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for the manipulation of convex polyhedra

LICENSE=	GPLv3+

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	libglpk.so:${PORTSDIR}/math/glpk \
		libgmp.so:${PORTSDIR}/math/gmp

USES=		gmake perl5 tar:xz libtool
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debugging \
		--enable-optimization \
		--enable-documentation \
		--with-cflags="${CFLAGS}" \
		--with-cxxflags="${CXXFLAGS}" \
		--with-gmp-include="${LOCALBASE}/include" \
		--with-gmp-lib="${LOCALBASE}/lib" \
		--enable-interfaces="${INTERFACES}"
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# Only enable C and C++ interfaces. Checks for java, prolog and ocaml
# have to be added.
INTERFACES=	c,cxx

post-patch:
	@${REINPLACE_CMD} -e \
		'/OPT_FLAGS/s|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/for file in/s|COPYING||' ${WRKSRC}/doc/Makefile.in

post-install:
.for i in libppl.so libppl_c.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${i}
.endfor

.include <bsd.port.mk>
