# New ports collection makefile for:	opendx
# Version required:	4.0.9
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	dx-4.0.9
PKGNAME=	opendx-4.0.9
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3 \
		netcdf.1:${PORTSDIR}/math/netcdf

USE_XLIB=	yes
REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -Dfreebsd -I${PREFIX}/include" \
		CPPFLAGS="-I${PREFIX}/include" \
		CXXFLAGS="${CFLAGS} -Dfreebsd -I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"
NO_MTREE=	yes
PLIST_SUB=	ARCH=${MACHINE_ARCH}

post-patch:
	@find ${WRKSRC} -name Makefile.in | \
	  xargs /usr/bin/perl -pi -e 's/-lXm /\$${MOTIFLIB} /g'

.include <bsd.port.mk>
