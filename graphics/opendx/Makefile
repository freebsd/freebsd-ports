# New ports collection makefile for:	opendx
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx
PORTVERSION=	4.1.0
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3 \
		netcdf.1:${PORTSDIR}/math/netcdf

USE_XLIB=	yes
REQUIRES_MOTIF=	yes
USE_NEWGCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -Dfreebsd -I${PREFIX}/include" \
		CPPFLAGS="-I${PREFIX}/include" \
		CXXFLAGS="${CFLAGS} -Dfreebsd -I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"
NO_MTREE=	yes
PLIST_SUB=	ARCH=${MACHINE_ARCH}

post-patch:
	@find ${WRKSRC} -name Makefile.in | \
	  xargs ${PERL} -pi -e 's/-lXm /\$${MOTIFLIB} /g'

.include <bsd.port.mk>
