# Created by: shurd
# $FreeBSD$

PORTNAME=	svxlink
PORTVERSION=	13.12
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/svxlink/svxlink/${PORTVERSION}

MAINTAINER=	shurd@sasktel.net
COMMENT=	General purpose ham radio voice services and Qtel Echolink client

LICENSE=	GPLv2

LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm \
		libspeex.so:${PORTSDIR}/audio/speex \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libpopt.so:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf \
		${LOCALBASE}/include/linux/input.h:${PORTSDIR}/multimedia/v4l_compat

USES=		gmake tcl
USE_LDCONFIG=	yes

MAKE_FLAGS=	LIB_INSTALL_DIR=${LOCALBASE}/lib \
		INC_INSTALL_DIR=${LOCALBASE}/include/svxlink \
		BIN_INSTALL_DIR=${LOCALBASE}/bin \
		SBIN_INSTALL_DIR=${LOCALBASE}/sbin \
		PLUGIN_INSTALL_DIR=${LOCALBASE}/lib/svxlink \
		TCL_LIBDIR=${TCL_LIBDIR} \
		ADD_INCPATH=-I${LOCALBASE}/include

OPTIONS_DEFINE=	QTEL
QTEL_DESC=	Build Qtel EchoLink client
OPTIONS_DEFAULT=QTEL
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQTEL}
USE_QT4=	corelib gui network moc_build linguist_build rcc_build uic_build
MAKE_ENV+=	MOC=${MOC} \
		RCC=${RCC} \
		UIC=${UIC} \
		LRELEASE=${LRELEASE} \
		QT_LIBDIR=${QT_LIBDIR} \
		QT_INCDIR=${QT_INCDIR} \
		QT_PREFIX=${QT_PREFIX}
.else
MAKE_ENV+=	WITHOUT_QT=yes
.endif

post-patch:
	@${GREP} -lr /usr/share/ ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/share/man|${MANPREFIX}/man|' \
		-e 's|/usr/share/doc/svxlink|${DOCSDIR}|' \
		-e 's|/usr/share/svxlink|${DATADIR}|' \
		-e 's|/usr/share/qtel|${PREFIX}/share/qtel|' \
		-e 's|/usr/share/applications|${DESKTOPDIR}|' \
		-e 's|/usr/share/icons|${PREFIX}/share/icons|'
	@${GREP} -lr /dev/ttyS0 ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|/dev/ttyS0|/dev/ttyu0|'
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|' ${WRKSRC}/qtel/qtel.desktop
	@${REINPLACE_CMD} -e 's|/usr/lib|${PREFIX}/lib|' \
		${WRKSRC}/doc/man/svxlink.conf.5 \
		${WRKSRC}/svxlink/svxlink/svxlink.conf
	@${GREP} -lr /etc/ ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|'
	@${GREP} -lr 'echo -e' ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} \
		-e 's|echo -en|echo -n|' \
		-e 's|echo -e|echo |'
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|,root,root|,root,wheel|'
	@${GREP} -lr alsa:default ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|alsa:default|oss:/dev/dsp|'
	@${GREP} -lr alsa:plughw:0 ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|alsa:plughw:0|oss:/dev/dsp|'

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

.include <bsd.port.mk>
