PORTNAME=	fldigi
DISTVERSION=	4.2.09
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia
WWW=		https://www.w1hkj.org/FldigiHelp/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		docbook-xsl>=1.0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng16.so:graphics/png \
		libportaudio.so:audio/portaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libudev.so:devel/libudev-devd

USES=		autoreconf:build compiler:c++11-lib desktop-file-utils gmake \
		jpeg perl5 pkgconfig shebangfix xorg
USE_CXXSTD=	gnu++0x
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimizations=none \
		--with-asciidoc \
		--with-sndfile
CONFIGURE_ENV=	EXTRA_LIBS="-lexecinfo" \
		FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

OPTIONS_DEFINE=		DOCS FLARQ HAMLIB NLS OSS PULSEAUDIO
OPTIONS_DEFAULT=	FLARQ HAMLIB OSS
OPTIONS_SUB=		yes

FLARQ_DESC=	Compile flarq
HAMLIB_DESC=	Support rig control via hamlib

FLARQ_CONFIGURE_ENABLE=		flarq
HAMLIB_LIB_DEPENDS=		libhamlib.so:comms/hamlib
HAMLIB_CONFIGURE_WITH=		hamlib
NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls
OSS_CONFIGURE_ENABLE=		oss
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

post-configure:
	${RM} ${WRKSRC}/doc/*.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
