PORTNAME=	libgpod
PORTVERSION=	0.8.3
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	SF/gtkpod/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Library for direct access to iPod contents
WWW=		http://www.gtkpod.org/wiki/Libgpod

LICENSE=	LGPL20

LIB_DEPENDS=	libplist-2.0.so:devel/libplist \
		libtag.so:audio/taglib \
		libsgutils2.so:sysutils/sg3_utils

USES=		compiler:c++11-lang gettext gmake gnome libtool localbase \
		pkgconfig sqlite:3 tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-udev --without-hal \
		--without-python \
		--with-html-dir="${DOCSDIR:H}"
USE_CSTD=	gnu89
USE_GNOME=	gdkpixbuf intltool libxml2
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS IMOBILE
OPTIONS_DEFAULT=IMOBILE
OPTIONS_SUB=	yes

IMOBILE_DESC=	Apple iPhone/iPod Touch support

IMOBILE_LIB_DEPENDS=	libimobiledevice-1.0.so:comms/libimobiledevice
IMOBILE_CONFIGURE_WITH=	libimobiledevice

PORTDOCS=	ChangeLog NEWS README*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMOBILE}
COMMENT:=	${COMMENT:S,iPod,&/iPhone,}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libplist >= 1\.0|libplist-2.0 >= 2.0|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/ipod-time-sync \
		${STAGEDIR}${PREFIX}/bin
	@${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libgpod-sharp.pc

post-install-DOCS-on:
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
