# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easytag
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GTK Tag editor for audio files

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:${PORTSDIR}/textproc/docbook-xml \
	        ${LOCALBASE}/share/xsl/docbook/html/refentry.xsl:${PORTSDIR}/textproc/docbook-xsl \
	        itstool:${PORTSDIR}/textproc/itstool \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libid3.so:${PORTSDIR}/audio/id3lib \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libtag.so:${PORTSDIR}/audio/taglib

USES=		gmake pkgconfig pathfix desktop-file-utils tar:xz
USE_GNOME=	glib20 intltool intlhack libxslt
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GTK
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--disable-appdata-validate \
	--without-help-dir \
	--with-xml-catalog=${LOCALBASE}/share/xml/catalog

PORTDOCS=	HACKING THANKS TODO

OPTIONS_DEFINE=	WAVPACK NLS OPUS SPEEX
OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2 NLS
OPTIONS_SUB=	yes

WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	wavpack
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
OPUS_LIB_DEPENDS=	libopusfile.so:${PORTSDIR}/audio/opusfile
OPUS_CONFIGURE_ENABLE=	opus
SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ENABLE=	speex

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--with-gtk2
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=--without-gtk2
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
