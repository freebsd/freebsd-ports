# Created by: ijliao
# $FreeBSD$

PORTNAME=	ppl
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/%SUBDIR%/ \
		http://bugseng.com/products/ppl/download/ftp/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for the manipulation of convex polyhedra

LICENSE=	GPLv3 # (or later)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

OPTIONS_DEFINE=	DOCS

USE_XZ=		yes
USES=		gmake perl5
USE_PERL5=	build
USE_AUTOTOOLS=	libtool
INTERFACES=	c,cxx
PORTDOCS=	*

CONFIGURE_ARGS=	--disable-debugging \
		--enable-optimization \
		--with-cflags="${CFLAGS}" \
		--with-cxxflags="${CXXFLAGS}" \
		--with-gmp-include="${LOCALBASE}/include" \
		--with-gmp-lib="${LOCALBASE}/lib" \
		--enable-interfaces="${INTERFACES}"
USE_LDCONFIG=	yes

# Only enable C and C++ interfaces. Checks for java, prolog and ocaml
# have to be added.
INTERFACES=	c,cxx

post-patch:
	@${REINPLACE_CMD} -e \
		'/OPT_FLAGS/s|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-data-local|| ; \
		/for file in/s|COPYING||' ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} install-data-local)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libppl.so.12 \
		${STAGEDIR}${PREFIX}/lib/libppl_c.so.4

.include <bsd.port.mk>
