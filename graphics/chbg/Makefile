# Created by: Peter Jones <p@dancris.com>
# $FreeBSD$

PORTNAME=	chbg
PORTVERSION=	1.5
PORTREVISION=	14
CATEGORIES=	graphics gnome
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change Background Picture with time period

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_GNOME=	gdkpixbuf
USE_GMAKE=	yes
USES=		gettext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--disable-gnome

NO_STAGE=	yes
.include <bsd.port.pre.mk>

MAN1=		chbg.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
