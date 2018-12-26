# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easytag
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GTK Tag editor for audio files

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:textproc/docbook-xml \
	        ${LOCALBASE}/share/xsl/docbook/html/refentry.xsl:textproc/docbook-xsl \
	        itstool:textproc/itstool \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libid3.so:audio/id3lib \
		libid3tag.so:audio/libid3tag \
		libvorbis.so:audio/libvorbis \
		libFLAC.so:audio/flac \
		libtag.so:audio/taglib \
		libogg.so:audio/libogg

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gmake \
		gnome localbase pkgconfig tar:xz
USE_GNOME=	cairo dconf:run gtk30 intlhack libxslt
GLIB_SCHEMAS=	org.gnome.EasyTAG.gschema.xml org.gnome.EasyTAG.enums.xml
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-DHAVE_GTK

CONFIGURE_ARGS=	--disable-appdata-validate \
	--without-help-dir \
	--with-xml-catalog=${LOCALBASE}/share/xml/catalog

PORTDOCS=	HACKING THANKS TODO

OPTIONS_DEFINE=	WAVPACK NLS OPUS SPEEX DOCS
OPTIONS_DEFAULT=	WAVPACK OPUS SPEEX
OPTIONS_SUB=	yes

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	wavpack
NLS_CONFIGURE_ENABLE=	nls
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile \
			libopus.so:audio/opus
OPUS_CONFIGURE_ENABLE=	opus
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_ENABLE=	speex

NLS_USES=		gettext-runtime

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

pre-configure:
	@${REINPLACE_CMD} -e 's,^DATADIRNAME = @DATADIRNAME@,DATADIRNAME = share,' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
