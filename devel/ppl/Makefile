# Created by: ijliao
# $FreeBSD$

PORTNAME=	ppl
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/${PORTVERSION}/ \
		http://bugseng.com/products/ppl/download/ftp/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for the manipulation of convex polyhedra

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm4:devel/m4
LIB_DEPENDS=	libglpk.so:math/glpk \
		libgmp.so:math/gmp

BROKEN_aarch64=		fails to compile: ./OR_Matrix_inlines.hh:100:8: error: missing 'typename' prior to dependent type template name 'OR_Matrix<T>::Pseudo_Row'
BROKEN_armv6=		fails to compile: ./OR_Matrix_inlines.hh:100:8: error: missing 'typename' prior to dependent type template name 'OR_Matrix<T>::Pseudo_Row'
BROKEN_armv7=		fails to compile: ./OR_Matrix_inlines.hh:100:8: error: missing 'typename' prior to dependent type template name 'OR_Matrix<T>::Pseudo_Row'

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
INSTALL_TARGET=	install-strip
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

.include <bsd.port.mk>
