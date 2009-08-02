# ex:ts=8
# New ports collection makefile for:	ppl
# Date created:			Feb 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ppl
PORTVERSION=	0.10.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/%SUBDIR%/ \
		http://www.cs.unipr.it/ppl/Download/ftp/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	grosser@fim.uni-passau.de
COMMENT=	The Parma Polyhedra Library

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
USE_GNOME=	gnometarget
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	configure Watchdog/configure
USE_GCC=	4.2+

# Only enable C and C++ interfaces. Checks for java, prolog and ocaml
# have to be added.
INTERFACES=	c,cxx

CONFIGURE_ARGS=	--disable-debugging \
		--enable-optimization \
		--with-cflags="${CFLAGS}" \
		--with-cxxflags="${CXXFLAGS}" \
		--with-libgmp-prefix="${LOCALBASE}" \
		--with-libgmpxx-prefix="${LOCALBASE}" \
		--enable-interfaces="${INTERFACES}"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	ppl-config.1 ppl_lcdd.1
MAN3=	libppl.3 libppl_c.3

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||g' \
		${WRKSRC}/doc/Makefile.in ${WRKSRC}/Watchdog/doc/Makefile.in
.endif

.include <bsd.port.mk>
