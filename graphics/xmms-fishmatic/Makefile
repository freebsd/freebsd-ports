# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-fishmatic
PORTVERSION=	0.0.1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://stukach.com/hosted/
DISTNAME=	fishmatic

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS non-static OpenGL stereogram visualization plugin

BUILD_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms

USES=		gmake pkgconfig
USE_XORG=	xext
USE_GNOME=      gtk12
USE_GL=		glut
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/xmms/Visualization/libfishmatic.so

post-patch:
	@${REINPLACE_CMD} -e \
		's|"-lpthread|"-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-O2|| ; \
		 s|@PNG_LIBS@||' ${WRKSRC}/Makefile.in

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Visualization
	(cd ${WRKSRC}/.libs && ${INSTALL_LIB} libfishmatic.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Visualization)

.include <bsd.port.mk>
