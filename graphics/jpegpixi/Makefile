# New ports collection makefile for:	jpegpixi
# Date created:		28 May 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	jpegpixi
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.zero-based.org/software/jpegpixi/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Useful to correct images from digtal camera with CCD defects

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MANLANG=	"" de fi fr
MAN1=		jpeghotp.1 jpegpixi.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
