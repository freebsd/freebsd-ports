# ex:ts=8
# New ports collection makefile for:	ppl
# Date created:			Feb 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ppl
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/%SUBDIR%/ \
		http://www.cs.unipr.it/ppl/Download/ftp/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Parma Polyhedra Library

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
USE_GNOME=	gnometarget
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	configure Watchdog/configure
CONFIGURE_ARGS=	--disable-debugging \
		--enable-optimization \
		--with-cflags="${CFLAGS}" \
		--with-cxxflags="${CXXFLAGS}" \
		--with-libgmp-prefix="${LOCALBASE}" \
		--with-libgmpxx-prefix="${LOCALBASE}"
USE_LDCONFIG=	yes

MAN1=	ppl-config.1 ppl_lcdd.1 ppl_lpsol.1

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||g' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
