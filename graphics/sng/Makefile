# ex:ts=8
# New ports collection makefile for:	sng
# Date created:			Mar 20, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sng
PORTVERSION=	0.9.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/X11/rgb.txt:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-png-inc=${LOCALBASE}/include \
		--with-rgbtxt=${X11BASE}/lib/X11/rgb.txt

USE_GMAKE=	yes

MAN1=	sng.1

pre-patch:
	@${PERL} -pi -e 's|-static||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
