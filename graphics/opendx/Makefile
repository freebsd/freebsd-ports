# New ports collection makefile for:	opendx
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx
PORTVERSION=	4.1.3
PORTREVISION=	1
CATEGORIES=	graphics math
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/ \
	        http://opendx.npaci.edu/source/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Magick.5:${PORTSDIR}/graphics/ImageMagick \
		df.1:${PORTSDIR}/graphics/hdf \
		netcdf.1:${PORTSDIR}/math/netcdf \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BISON=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_MOTIF=	yes
USE_NEWGCC=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-magick
CONFIGURE_ENV=	ARCH="" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${PREFIX}/include" \
		CPPFLAGS="-I${PREFIX}/include" \
		CXXFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib ${LDFLAGS} ${PTHREAD_LIBS}"
NO_MTREE=	yes
PLIST_SUB=	ARCH=${OPSYS:L}

post-patch:
	@${RM} -f ${WRKSRC}/include/stamp-h.in

post-configure:
	${PERL} -pi -e "s;flex ;flex -l ;g" ${WRKSRC}/src/uipp/dxuilib/Makefile

post-install:
	@${ECHO_MSG} "===>   Fixing path in the docs (/usr/lpp -> ${PREFIX})"
.for dir in doc help html man
	@find ${PREFIX}/dx/${dir} -type f | \
	  xargs ${PERL} -pi -e "s;/usr/lpp;${PREFIX};g"
.endfor

.include <bsd.port.mk>
