# New ports collection Makefile for: 	terminatorx
# Date created:			13 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	terminatorx
PORTVERSION=	3.82
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.terminatorx.cx/dist/
DISTNAME=	terminatorX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime audio synthesizer that allows you to "scratch" on audio data

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		lrdf.2:${PORTSDIR}/textproc/liblrdf \
		jack.0:${PORTSDIR}/audio/jack

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20 libxml2
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-alsa \
		--disable-alsamidi
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN1=		terminatorX.1

.if !defined(WITHOUT_MPG123)
BUILD_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.else
CONFIGURE_ARGS+=	--disable-mpg123
.endif

.if !defined(WITHOUT_SOX)
BUILD_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.else
CONFIGURE_ARGS+=	--disable-sox
.endif

.if !defined(WITHOUT_VORBIS)
BUILD_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/mad
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

pre-everything::
.if !defined(WITHOUT_MPG123)
	@${ECHO_MSG} "You can disable support for mpg123 by defining WITHOUT_MPG123."
.endif

.if !defined(WITHOUT_SOX)
	@${ECHO_MSG} "You can disable support for sox by defining WITHOUT_SOX."
.endif

.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif

.if !defined(WITHOUT_MAD)
	@${ECHO_MSG} "You can disable support for mad by defining WITHOUT_MAD."
.endif

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${GREP} -lR "%%LOCALBASE%%" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g'
	@${GREP} -lR "%%X11BASE%%" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|%%X11BASE%%|${LOCALBASE}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/terminatorX ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/terminatorX.1 ${MANPREFIX}/man/man1
.for file in terminatorX-app.png terminatorX-mime.png
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${file} \
		${PREFIX}/share/gnome/pixmaps
.endfor
.for file in terminatorX.mime terminatorX.keys
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${file} \
		${PREFIX}/share/gnome/mime-info
.endfor
	${INSTALL_DATA} ${WRKSRC}/gnome-support/terminatorX.desktop \
		${PREFIX}/share/gnome/apps/Multimedia
	@${MKDIR} ${PREFIX}/share/gnome/help/terminatorX/C
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual.xml \
		${PREFIX}/share/gnome/help/terminatorX/C/terminatorX.xml
	@${MKDIR} ${PREFIX}/share/gnome/help/terminatorX/C/figures
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/figures/signalflow.png \
		${PREFIX}/share/gnome/help/terminatorX/C/figures
	@${MKDIR} ${PREFIX}/share/gnome/omf/terminatorX
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual-C.omf \
		${PREFIX}/share/gnome/omf/terminatorX/terminatorX-C.omf
	@scrollkeeper-install -q ${PREFIX}/share/gnome/omf/terminatorX/terminatorX-C.omf 2>/dev/null || ${TRUE}

.include <bsd.port.mk>
