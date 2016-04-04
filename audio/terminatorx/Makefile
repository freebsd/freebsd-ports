# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/audio/terminatorx/Makefile,v 1.6 2007/08/04 03:51:28 marcus Exp $

PORTNAME=	terminatorx
PORTVERSION=	3.84
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://terminatorx.org/dist/
DISTNAME=	terminatorX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime audio synthesizer that allows you to "scratch" on audio data

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		rarian-sk-config:textproc/rarian
LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		liblrdf.so:textproc/liblrdf

OPTIONS_DEFINE=	ALSA JACK MPG123 SOX VORBIS MAD
OPTIONS_DEFAULT=	JACK MPG123 SOX VORBIS MAD
SOX_DESC=	sox (.au) support
MPG123_DESC=	mpg123 support

USE_XORG=	x11 xext xi xxf86dga ice sm
USES=		tar:bzip2 gmake pathfix pkgconfig autoreconf
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsamidi \
		--disable-scheduler
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-alsa
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-jack
MPG123_BUILD_DEPENDS=	mpg123:audio/mpg123
MPG123_RUN_DEPENDS=	mpg123:audio/mpg123
MPG123_CONFIGURE_OFF=	--disable-mpg123
SOX_BUILD_DEPENDS=	sox:audio/sox
SOX_RUN_DEPENDS=	sox:audio/sox
SOX_CONFIGURE_OFF=	--disable-sox
VORBIS_BUILD_DEPENDS=	oggenc:audio/vorbis-tools
VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_OFF=	--disable-vorbis
MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_OFF=	--disable-mad

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${GREP} -lR "%%LOCALBASE%%" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/terminatorX ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/terminatorX.1 ${STAGEDIR}${MANPREFIX}/man/man1
.for file in terminatorX-app.png terminatorX-mime.png
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${file} \
		${STAGEDIR}${PREFIX}/share/pixmaps
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mime-info
.for f in terminatorX.mime terminatorX.keys
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${f} \
		${STAGEDIR}${PREFIX}/share/mime-info
.endfor
	${INSTALL_DATA} ${WRKSRC}/gnome-support/terminatorX.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome/help/terminatorX/C
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual.xml \
		${STAGEDIR}${PREFIX}/share/gnome/help/terminatorX/C/terminatorX.xml
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome/help/terminatorX/C/figures
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/figures/signalflow.png \
		${STAGEDIR}${PREFIX}/share/gnome/help/terminatorX/C/figures
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/omf/terminatorX
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual-C.omf \
		${STAGEDIR}${PREFIX}/share/omf/terminatorX/terminatorX-C.omf

.include <bsd.port.mk>
