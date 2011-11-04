# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	3.21.12
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/fldigi/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LICENSE=	GPLv3

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		samplerate:${PORTSDIR}/audio/libsamplerate

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xsltproc:${PORTSDIR}/textproc/libxslt

BROKEN=		does not compile

GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes

MAN1=		fldigi.1 

OPTIONS=	NATIVE_OPT	"Enable Native Optimizations"		off \
		NLS		"Use NLS"				off \
		FLARQ		"Compile flarq"				on \
		XMLRPC		"Support XMLrpc (fldigi-shell)"		off \
		OSS		"Support OSS"				on \
		SNDFILE		"Support for libsndfile"		off \
		PORTAUDIO	"PortAudio support"			off \
		PULSEAUDIO	"PulseAudio support"			off \
		HAMLIB		"Support rig control via hamlib"	on \

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif
.if ${ARCH} == "sparc64"
BROKEN=		Fails to install
.endif
.if defined(WITH_NATIVE_OPT)
CONFIGURE_ARGS+=--enable-optimizations=native
.else
CONFIGURE_ARGS+=--enable-optimizations=none
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif
.if defined(WITHOUT_FLARQ)
CONFIGURE_ARGS+=--disable-flarq
PLIST_SUB+=	FLARQ="@comment "
.else
CONFIGURE_ARGS+=--enable-flarq
MAN1+=		flarq.1
PLIST_SUB+=	FLARQ=""
.endif
.if defined(WITH_XMLRPC)
CONFIGURE_ARGS+=--with-xmlrpc
LIB_DEPENDS+=	xmlrpc:${PORTSDIR}/net/xmlrpc-c
PLIST_SUB+=	XMLRPC=""
MAN1+=		fldigi-shell.1
.else
CONFIGURE_ARGS+=--without-xmlrpc
PLIST_SUB+=	XMLRPC="@comment "
.endif
.if defined(WITH_OSS)
CONFIGURE_ARGS+=--enable-oss
.else
CONFIGURE_ARGS+=--disable-oss
.endif
.if defined(WITH_SNDFILE)
CONFIGURE_ARGS+=--with-sndfile
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=--without-sndfile
.endif
.if defined(WITH_PORTAUDIO)
CONFIGURE_ARGS+=--with-portaudio
BUILD_DEPENDS+=	${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2
.else
CONFIGURE_ARGS+=--without-portaudio
.endif
.if defined(WITH_PULSEAUDIO)
CONFIGURE_ARGS+=--with-pulseaudio
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--without-pulseaudio
.endif
.if defined(WITH_HAMLIB)
CONFIGURE_ARGS+=--with-hamlib
LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib
.else
CONFIGURE_ARGS+=--without-hamlib
.endif
.if	!defined(NOPORTDOCS)
CONFIGURE_ARGS+=--with-asciidoc
PLIST_SUB	+=ASCIIDOC=""
.else
CONFIGURE_ARGS+=--without-asciidoc
PLIST_SUB+=	ASCIIDOC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|png_infopp_NULL|NULL|' \
		 ${WRKSRC}/src/widgets/picture.cxx

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|^CPPFLAGS|#CPPFLAGS|' \
		${WRKSRC}/src/Makefile

do-build:
# It will not build the man pages without the rm
	(cd ${WRKSRC}/doc/;rm *.1;gmake;cd ${WRKSRC}/src;gmake)

post-install:
.if	!defined(NOPORTDOCS)
	@${ECHO} ""
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${DOCSDIR}
	@${ECHO} "fldigi docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
