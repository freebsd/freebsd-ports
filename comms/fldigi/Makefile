PORTNAME=	fldigi
DISTVERSION=	4.2.04
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME} \
		http://www.w1hkj.com/files/fldigi/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia
WWW=		http://www.w1hkj.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		docbook-xsl>=1.0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libportaudio.so:audio/portaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libudev.so:devel/libudev-devd

USES=		autoreconf compiler:c++11-lib desktop-file-utils gmake jpeg \
		perl5 pkgconfig shebangfix xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

USE_CXXSTD=	gnu++0x
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ENV=	EXTRA_LIBS="-lexecinfo" \
		FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"
CONFIGURE_ARGS=	--with-asciidoc \
		--with-sndfile \
		--enable-optimizations=none

OPTIONS_DEFINE=	DOCS FLARQ HAMLIB NLS OSS PULSEAUDIO
OPTIONS_DEFAULT=FLARQ HAMLIB OSS
OPTIONS_SUB=	yes

FLARQ_DESC=	Compile flarq
HAMLIB_DESC=	Support rig control via hamlib

FLARQ_CONFIGURE_ENABLE=		flarq
HAMLIB_LIB_DEPENDS=		libhamlib.so:comms/hamlib
HAMLIB_CONFIGURE_WITH=		hamlib
OSS_CONFIGURE_ENABLE=		oss
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls

post-configure:
	${RM} ${WRKSRC}/doc/*.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
