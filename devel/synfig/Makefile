# New ports collection makefile for:	synfig
# Date created:				25 Jun 2006
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	synfig
DISTVERSION=	0.61.06
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A vector based 2D animation package

LIB_DEPENDS=	xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Magick.10:${PORTSDIR}/graphics/ImageMagick \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		dv.4:${PORTSDIR}/multimedia/libdv \
		IlmImf.4:${PORTSDIR}/graphics/OpenEXR
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	gnomehack

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

post-patch:
	@${REINPLACE_CMD} 's|TARGET_MNG="no"|TARGET_MNG="yes"|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
