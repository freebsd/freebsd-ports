# New ports collection makefile for:	opendx
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
# Updates:              Randall Hopper <rhh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx
PORTVERSION=	4.2.0
PORTREVISION=	0
CATEGORIES=	graphics math
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/ \
	        http://opendx.npaci.edu/source/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Magick.5:${PORTSDIR}/graphics/ImageMagick \
		df.1:${PORTSDIR}/graphics/hdf \
		netcdf.1:${PORTSDIR}/math/netcdf \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_AUTOMAKE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_MOTIF=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
AUTOMAKE_ARGS=	-a -i
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-javadx
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
	${REINPLACE_CMD} -e "s;flex ;flex -l ;g" ${WRKSRC}/src/uipp/dxuilib/Makefile

post-install:
	@${ECHO_MSG} "===>   Fixing path in the docs (/usr/lpp -> ${PREFIX})"
.for dir in doc help html man
	@${FIND} ${PREFIX}/dx/${dir} -type f | \
	  ${XARGS} ${REINPLACE_CMD} -e "s;/usr/lpp;${PREFIX};g"
.endfor

.include <bsd.port.mk>
