# New ports collection makefile for:	libexif-gtk
# Date created:		10 Jun 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libexif-gtk
PORTVERSION=	0.3.5
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libexif

MAINTAINER=	marius@nuenneri.ch
COMMENT=	GTK+ widgets to display/edit EXIF tags

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif

USE_GNOME=	gnomehack gnometarget gtk20
USE_AUTOTOOLS=	autoconf:262 libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
