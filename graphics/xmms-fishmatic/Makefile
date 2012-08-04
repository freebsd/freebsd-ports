# New ports collection makefile for:	xmms-fishmatic
# Date created:				20 Jan 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-fishmatic
PORTVERSION=	0.0.1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://stukach.com/hosted/
DISTNAME=	fishmatic

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XMMS non-static OpenGL stereogram visualization plugin

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libfishmatic.so
USE_GNOME=      gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
USE_GL=		glut
USE_XORG=	xext
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBS="-lGL -lXext ${LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-patch:
	@${RM} -f ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e 's|-O2||; \
		s|-lpthreads|${PTHREAD_LIBS:S/"//g}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
