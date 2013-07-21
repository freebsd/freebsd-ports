# Created by: ijliao
# $FreeBSD$

PORTNAME=	ppl
PORTVERSION=	0.11.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/%SUBDIR%/ \
		http://www.cs.unipr.it/ppl/Download/ftp/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Parma Polyhedra Library

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

BROKEN=		fails to build
DEPRECATED=	obsolete version; fails to build
EXPIRATION_DATE=	2013-09-21

PWL_DOC_PREFIX=	share/doc/pwl

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure Watchdog/configure
USE_GCC=	4.2+

# Only enable C and C++ interfaces. Checks for java, prolog and ocaml
# have to be added.
INTERFACES=	c,cxx

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-debugging \
		--enable-optimization \
		--with-cflags="${CFLAGS}" \
		--with-cxxflags="${CXXFLAGS}" \
		--with-gmp-prefix="${LOCALBASE}" \
		--enable-interfaces="${INTERFACES}"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	ppl-config.1 ppl_lcdd.1 ppl_pips.1
MAN3=	libppl.3 libppl_c.3

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||g' \
		${WRKSRC}/doc/Makefile.in ${WRKSRC}/Watchdog/doc/Makefile.in
.endif

PLIST_SUB+=	PWL_DOC_PREFIX=${PWL_DOC_PREFIX}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=		Does not compile on sparc64-9: complains about fpu-sparc.inlines.hh
.endif

.include <bsd.port.post.mk>
