# New ports collection makefile for:    libexif
# Date created:        Tue Feb 26 19:02:44 MST 2002
# Whom:                Peter Schmiedeskamp
#
# $FreeBSD$
#

PORTNAME=	libexif
PORTVERSION=	0.5.12
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	Library to read digital camera file meta-data

USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-g -Wall||g' ${WRKSRC}/configure

.include <bsd.port.mk>
