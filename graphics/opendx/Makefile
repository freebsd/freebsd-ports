# New ports collection makefile for:	opendx
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
# Updates:              Randall Hopper <rhh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx
PORTVERSION=	4.3.2
PORTREVISION=	1
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IBM's Open Visualization Data Explorer

LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick \
		df.1:${PORTSDIR}/graphics/hdf \
		netcdf.1:${PORTSDIR}/math/netcdf \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_REINPLACE=	yes
USE_BISON=	yes
USE_MESA=	yes
USE_MOTIF=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --without-javadx
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	ARCH="freebsd" \
		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GMAKE=	yes
NO_MTREE=	yes
PLIST_SUB=	ARCH=${OPSYS:L}

post-patch:
	@${RM} -f ${WRKSRC}/include/stamp-h.in
.for dir in doc help html man
	@${FIND} ${WRKSRC}/${dir} -type f | ${XARGS} \
		${REINPLACE_CMD} -e "s;/usr/lpp;${PREFIX};g"
.endfor

.include <bsd.port.mk>
