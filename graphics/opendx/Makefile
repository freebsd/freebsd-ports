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
CONFIGURE_ARGS=	--without-magick
CONFIGURE_ENV=	ARCH="" \
		CFLAGS="${CFLAGS} -I${PREFIX}/include" \
		CPPFLAGS="-I${PREFIX}/include" \
		CXXFLAGS="${CFLAGS} -I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"
NO_MTREE=	yes
PLIST_SUB=	ARCH=${OPSYS:L}

post-patch:
	@find ${WRKSRC} -name Makefile.am | \
	  xargs ${PERL} -pi -e "s;-lXm ;${MOTIFLIB} ;g"
	@${RM} -f ${WRKSRC}/include/stamp-h.in

pre-configure:
	@cd ${WRKSRC} && aclocal && ${SETENV} ${CONFIGURE_ENV} autoheader

post-install:
	@${ECHO_MSG} "===>   Fixing path in the docs (/usr/lpp -> ${PREFIX})"
.for dir in doc help html man
	@find ${PREFIX}/dx/${dir} -type f | \
	  xargs ${PERL} -pi -e "s;/usr/lpp;${PREFIX};g"
.endfor

.include <bsd.port.mk>
