# New ports collection makefile for:	opendx
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	df.1:${PORTSDIR}/graphics/hdf \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		netcdf.1:${PORTSDIR}/math/netcdf \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ttf.4:${PORTSDIR}/print/freetype

USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_MOTIF=	yes
USE_NEWGCC=	yes
USE_XLIB=	yes
AUTOMAKE_ARGS=	-a -i
CONFIGURE_ENV=	ARCH="" \
		CFLAGS="${CFLAGS} -I${PREFIX}/include" \
		CPPFLAGS="-I${PREFIX}/include" \
		CXXFLAGS="${CFLAGS} -I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"
NO_MTREE=	yes
PLIST_SUB=	ARCH=${OPSYS:L}

# XXX the -lcompat below is an ugly kludge. opendx's code
#     should be fixed to use the modern POSIX style regcomp(3)
#     instead of the old V8 style one.
post-patch:
	@find ${WRKSRC} -name Makefile.am | \
	  xargs ${PERL} -pi -e "s;-lXm ;-lcompat ${MOTIFLIB} ;g"

pre-configure:
	@cd ${WRKSRC} && aclocal

.include <bsd.port.mk>
