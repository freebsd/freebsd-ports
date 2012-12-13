# Created by: Thawatchai Piyawat <piyawat@usablelabs.com>
# $FreeBSD$

PORTNAME=	libthai
PORTVERSION=	0.1.5
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thai language support library

LICENSE=	LGPL21

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --force-missing --foreign
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

MAN3=	libthai.3 thctype.3 wtt.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} > 800000
ALL_TARGET=	all
.else
ALL_TARGET= all check
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^pkgconfigdir/s|=.*|= $$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
