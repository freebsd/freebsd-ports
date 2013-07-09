# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	gphoto2
PORTVERSION=	2.4.14
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/gphoto/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command-line frontend to libgphoto2

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		gphoto2:${PORTSDIR}/graphics/libgphoto2

USES=		pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-cdk
MAKE_JOBS_SAFE=	yes

MAN1=		gphoto2.1

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	AALIB DOCS NLS
OPTIONS_DEFAULT=	AALIB
AALIB_DESC=	Command line capture preview (aalib)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAALIB}
LIB_DEPENDS+=	aa:${PORTSDIR}/graphics/aalib \
		jpeg:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=--without-aalib --without-jpeg
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREADS_LIBS:S/"//g}|g ; \
		 s|-g -Wall||g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
.for file in NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
