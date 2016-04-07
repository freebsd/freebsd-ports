# Created by: shurd
# $FreeBSD$

PORTNAME?=	svxlink
PORTVERSION=	15.11
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT?=	General purpose ham radio voice services

LICENSE=	GPLv2

LIB_DEPENDS?=	libgsm.so:audio/gsm \
		libspeex.so:audio/speex \
		libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt \
		libsigc-2.0.so:devel/libsigc++20 \
		libpopt.so:devel/popt \
		libopus.so:audio/opus
BUILD_DEPENDS=	pkg-config:devel/pkgconf \
		${LOCALBASE}/include/linux/input.h:multimedia/v4l_compat

USE_GITHUB=	yes
GH_ACCOUNT=	sm0svx
GH_PROJECT=	svxlink

USES=		cmake tcl
CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:FILEPATH=${MANDIRS} \
		-DLOCAL_STATE_DIR=/var
.if ${PORTNAME}==svxlink
CMAKE_ARGS+=	-DUSE_QT:BOOL=NO
.endif
USE_LDCONFIG=	yes

ALL_TARGET?=	all man
OPTIONS_DEFINE=	DOCS STATIC
STATIC_DESC=	Build and install static libraries
STATIC_CMAKE_ON=	-DBUILD_STATIC_LIBS=YES
.if ${PORTNAME}==svxlink
OPTIONS_DEFAULT=OSS ALSA
OPTIONS_MULTI=	SOUND
OPTIONS_MULTI_SOUND=	ALSA OSS
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_OFF=	-DUSE_ALSA:BOOL=OFF
ALSA_CMAKE_ON=	-DUSE_ALSA:BOOL=ON
OSS_CMAKE_OFF=	-DUSE_OSS:BOOL=OFF
OSS_CMAKE_ON=	-DUSE_OSS:BOOL=ON
.endif
DOCS_ALL_TARGET=doc
DOCS_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen:BOOL=TRUE
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
OPTIONS_SUB=	yes
PORTDOCS=	*

post-patch:
	@${GREP} -lr /dev/ttyS0 ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|/dev/ttyS0|/dev/ttyu0|'
	@${REINPLACE_CMD} -e 's|/usr/share/icons|${PREFIX}/share/icons|' \
		${WRKSRC}/src/qtel/qtel.desktop
	@${REINPLACE_CMD} -e 's|/usr/share/svxlink|${DOCSDIR}|' \
		${WRKSRC}/src/doc/man/svxlink.conf.5
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|' ${WRKSRC}/src/qtel/qtel.desktop \
		${WRKSRC}/src/doc/man/svxlink.conf.5 \
		${WRKSRC}/src/svxlink/svxlink/svxlink.conf.in
	@${REINPLACE_CMD} -e 's|/usr/lib|${PREFIX}/lib|' \
		${WRKSRC}/src/doc/man/svxlink.conf.5 \
		${WRKSRC}/src/svxlink/svxlink/svxlink.conf.in
post-patch-OSS-on:
	@${GREP} -lr alsa:default ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|alsa:default|oss:/dev/dsp|'
	@${GREP} -lr alsa:plughw:0 ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|alsa:plughw:0|oss:/dev/dsp|'

.if ${PORTNAME}==svxlink
post-stage:
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/.procmailrc \
		${STAGEDIR}${PREFIX}/etc/svxlink/.procmailrc.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/TclVoiceMail.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/TclVoiceMail.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/remotetrx.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/remotetrx.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleDtmfRepeater.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleDtmfRepeater.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleEchoLink.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleEchoLink.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleHelp.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleHelp.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleMetarInfo.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleMetarInfo.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleParrot.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleParrot.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModulePropagationMonitor.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModulePropagationMonitor.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleSelCallEnc.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleSelCallEnc.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleTclVoiceMail.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleTclVoiceMail.conf.sample
.endif

.include <bsd.port.mk>
