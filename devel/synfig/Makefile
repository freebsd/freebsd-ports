# New ports collection makefile for:	synfig
# Date created:				25 Jun 2006
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	synfig
DISTVERSION=	0.61.08
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A vector based 2D animation package

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl
LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		MagickWand.1:${PORTSDIR}/graphics/ImageMagick \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		dv.4:${PORTSDIR}/multimedia/libdv \
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26

BROKEN=		bad plist

USE_GNOME=	gnomehack gnometarget glib20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e '/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
	    /optimization_flags/s|CFLAGS=|#CFLAGS=|' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
