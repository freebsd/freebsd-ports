# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	gphoto2
PORTVERSION=	2.4.14
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/gphoto/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line frontend to libgphoto2

LICENSE=	GPLv2

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		gphoto2:${PORTSDIR}/graphics/libgphoto2

USES=		gmake pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-cdk

# XXX: do we still need to pass PTHREAD_* stuff here?
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	AALIB DOCS NLS
OPTIONS_DEFAULT=	AALIB
OPTIONS_SUB=	yes

AALIB_DESC=	Text mode capture preview support

AALIB_LIB_DEPENDS=	aa:${PORTSDIR}/graphics/aalib
AALIB_CONFIGURE_ARGS=	--without-aalib

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREADS_LIBS:S/"//g}|g ; \
		s|-g -Wall||g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
.endif

.include <bsd.port.mk>
