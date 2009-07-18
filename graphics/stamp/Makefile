# New ports collection makefile for:	stamp
# Date created:	11 August 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	stamp
PORTVERSION=	2.0.8
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	stamp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adds a graphical, configurable timestamp to a grayscale image

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	unfortunatly
.if !defined(WITHOUT_X11)
USE_GNOME=	gtk12
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local/share/stamp#${DATADIR}#' \
		${WRKSRC}/configure

.include <bsd.port.mk>
