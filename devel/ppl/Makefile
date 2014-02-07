# Created by: ijliao
# $FreeBSD$

PORTNAME=	ppl
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/%SUBDIR%/ \
		http://bugseng.com/products/ppl/download/ftp/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for the manipulation of convex polyhedra

LICENSE=	GPLv3 # (or later)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	libglpk.so:${PORTSDIR}/math/glpk \
		libgmp.so:${PORTSDIR}/math/gmp

USE_XZ=		yes
USES=		gmake perl5
USE_PERL5=	build
USE_AUTOTOOLS=	libtool
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
.for i in libppl.so.13 libppl_c.so.4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${i}
.endfor

.include <bsd.port.mk>
