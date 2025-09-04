PORTNAME=	gbsplay
DISTVERSION=	0.0.100
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Emulates the sound hardware of the Nintendo Game Boy(TM)
WWW=		https://github.com/mmitch/gbsplay

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lib desktop-file-utils gmake localbase:ldflags \
		shared-mime-info
USE_CSTD=	gnu89

USE_GITHUB=	yes
GH_ACCOUNT=	mmitch

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-pipewire \
		--mandir=${PREFIX}/share/man \
		--prefix=${PREFIX} \
		--sysconfdir=${PREFIX}/etc

MAKE_ENV+=	EXAMPLESDIR="${STAGEDIR}${EXAMPLESDIR}"

OPTIONS_DEFINE=		ALSA BASH_COMPLETIONS DOCS EXAMPLES NAS NLS PULSEAUDIO \
			SDL
OPTIONS_DEFAULT=	BASH_COMPLETIONS
OPTIONS_SUB=		yes

BASH_COMPLETIONS_DESC=	Install bash completions

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=		--disable-alsa
NAS_LIB_DEPENDS=		libaudio.so:audio/nas
NAS_CONFIGURE_ENABLE=		nas
NLS_USES=			gettext
NLS_CONFIGURE_OFF=		--disable-i18n
NLS_LDFLAGS=			-lintl
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse
SDL_USES=			sdl2
SDL_CONFIGURE_OFF=		--disable-sdl

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/\(gbsplayrc\)|${PREFIX}/etc/\1|" \
		${WRKSRC}/man/gbsplay.in.1 ${WRKSRC}/man/gbsplayrc.in.5

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/gbsplayrc_sample \
		${STAGEDIR}${PREFIX}/etc/gbsplayrc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gbsplay \
		${STAGEDIR}${PREFIX}/bin/gbsinfo ${STAGEDIR}${PREFIX}/bin/gbs2gb

post-install-BASH_COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/contrib/gbsplay.bashcompletion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}

.include <bsd.port.mk>
