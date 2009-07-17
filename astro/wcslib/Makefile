# ex:ts=4
# New ports collection makefile for:	wcslib
# Date created:							Wed Jul 15 10:09:45 EST 2009
# Whom:									Tony Maher <tonymaher@optusnet.com.au>
#
# $FreeBSD$

PORTNAME=		wcslib
PORTVERSION=	4.3.3
CATEGORIES=		astro
MASTER_SITES=	ftp://ftp.atnf.csiro.au/pub/software/wcslib/

MAINTAINER=		tonymaher@optusnet.com.au
COMMENT=		Library for parsing/generating FITS headers

GNU_CONFIGURE=	yes
USE_GMAKE=		yes
MAKEFILE=		GNUmakefile
USE_LDCONFIG=	yes

# See makedefs.in which describes why you want to set the extra support.
# For most users it will not be required.

OPTIONS=		CFITSIO "Add cfitsio support (for tests only)" Off \
				PGPLOT  "Add pgplot support (for tests only)" Off

.include <bsd.port.pre.mk>

# The configure script unconditionally searches for the cftisio library
# and uses it if found.

.if defined(WITH_CFITSIO) || exists(${LOCALBASE}/lib/libcfitsio.so)
PLIST_SUB+=		HPXCVT=""
LIB_DEPENDS+=	cfitsio:${PORTSDIR}/astro/cfitsio
.else
PLIST_SUB+=		HPXCVT="@comment "
.endif

.if defined(WITH_PGPLOT)
LIB_DEPENDS+=	pgplot.5:${PORTSDIR}/graphics/pgplot
.endif

.include <bsd.port.post.mk>
