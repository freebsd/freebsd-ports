# New ports collection makefile for:	opendx
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
# Updates:              Randall Hopper <rhh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx
PORTVERSION=	4.3.2
PORTREVISION=	4
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IBM's Open Visualization Data Explorer

LIB_DEPENDS=	Magick.8:${PORTSDIR}/graphics/ImageMagick \
		tiff.4:${PORTSDIR}/graphics/tiff

OPTIONS=	HDF "Build hdf-support (only hdf OR netcdf is supported)" on \
		NETCDF "Build netcdf-support" off

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GL=		yes
USE_MOTIF=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-javadx
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	ARCH="${OPSYS:L}" \
		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GMAKE=	yes
NO_MTREE=	yes
PLIST_SUB=	ARCH=${OPSYS:L}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
PLIST_SUB+=	UNAMEP=${ARCH} ARCHDIR=""
.else
PLIST_SUB+=	UNAMEP=${OPSYS:L} ARCHDIR="@comment "
.endif

.if defined(WITH_HDF)
LIB_DEPENDS+=	mfhdf.2:${PORTSDIR}/science/hdf
.endif

.if defined(WITH_NETCDF)
LIB_DEPENDS+=	netcdf.1:${PORTSDIR}/math/netcdf
.endif

post-patch:
	@${RM} -f ${WRKSRC}/include/stamp-h.in
.for dir in doc help html man
	@${FIND} ${WRKSRC}/${dir} -type f | ${XARGS} \
		${REINPLACE_CMD} -e "s;/usr/lpp;${PREFIX};g"
.endfor

.include <bsd.port.post.mk>
