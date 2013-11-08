# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/audio/terminatorx/Makefile,v 1.6 2007/08/04 03:51:28 marcus Exp $

PORTNAME=	terminatorx
PORTVERSION=	3.84
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://terminatorx.org/dist/
DISTNAME=	terminatorX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime audio synthesizer that allows you to "scratch" on audio data

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile \
		lrdf:${PORTSDIR}/textproc/liblrdf

OPTIONS_DEFINE=	ALSA JACK MPG123 SOX VORBIS MAD
OPTIONS_DEFAULT=	JACK MPG123 SOX VORBIS MAD
SOX_DESC=	sox (.au) support
MPG123_DESC=	mpg123 support

USE_BZIP2=	yes
NO_STAGE=	yes
USE_XORG=	x11 xext xi xxf86dga ice sm
USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomehier gtk20 libxml2
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--disable-alsamidi \
		--disable-scheduler
INSTALLS_OMF=	yes

MAN1=		terminatorX.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
CONFIGURE_ARGS+=	--disable-alsa
.else
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MMPG123}
BUILD_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.else
CONFIGURE_ARGS+=	--disable-mpg123
.endif

.if ${PORT_OPTIONS:MSOX}
BUILD_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.else
CONFIGURE_ARGS+=	--disable-sox
.endif

.if ${PORT_OPTIONS:MVORBIS}
BUILD_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/mad
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${GREP} -lR "%%LOCALBASE%%" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/terminatorX ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/terminatorX.1 ${MANPREFIX}/man/man1
.for file in terminatorX-app.png terminatorX-mime.png
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${file} \
		${PREFIX}/share/pixmaps
.endfor
.for f in terminatorX.mime terminatorX.keys
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${f} \
		${PREFIX}/share/mime-info
.endfor
	${INSTALL_DATA} ${WRKSRC}/gnome-support/terminatorX.desktop \
		${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/gnome/help/terminatorX/C
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual.xml \
		${PREFIX}/share/gnome/help/terminatorX/C/terminatorX.xml
	@${MKDIR} ${PREFIX}/share/gnome/help/terminatorX/C/figures
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/figures/signalflow.png \
		${PREFIX}/share/gnome/help/terminatorX/C/figures
	@${MKDIR} ${PREFIX}/share/omf/terminatorX
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual-C.omf \
		${PREFIX}/share/omf/terminatorX/terminatorX-C.omf
	@scrollkeeper-install -q ${PREFIX}/share/omf/terminatorX/terminatorX-C.omf 2>/dev/null || ${TRUE}

.include <bsd.port.mk>
