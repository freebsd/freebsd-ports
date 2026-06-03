PORTNAME=	morse
DISTVERSION=	2.6
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Morse Code Trainer
WWW=		http://www.catb.org/~esr/morse/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto>0:textproc/xmlto

USE_GITLAB=	yes
GL_ACCOUNT=	esr
GL_PROJECT=	morse-classic

PLIST_FILES=	bin/morsec \
		bin/QSO \
		share/man/man1/morsec.1.gz \
		share/man/man1/QSO.1.gz

OPTIONS_DEFAULT=	OSS
OPTIONS_SINGLE=		SOUND
OPTIONS_SINGLE_SOUND=	OSS PULSEAUDIO X11

OSS_DESC=		Beep using OSS (/dev/dsp)
PULSEAUDIO_DESC=	Beep using PulseAudio
X11_DESC=		Beep using X.Org Server

OSS_MAKE_ARGS=		DEVICE=OSS
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_USES=	pkgconfig
PULSEAUDIO_MAKE_ARGS=	DEVICE=PA
X11_BROKEN=		./alarm.h:15:15: error: a parameter list without types is only allowed in a function definition
X11_USES=		localbase:ldflags xorg
X11_USE=		XORG=x11
X11_MAKE_ARGS=		DEVICE=X11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/morse ${STAGEDIR}${PREFIX}/bin/morsec
	${INSTALL_PROGRAM} ${WRKSRC}/QSO ${STAGEDIR}${PREFIX}/bin/QSO
	${INSTALL_MAN} ${WRKSRC}/morse.1 ${STAGEDIR}${PREFIX}/share/man/man1/morsec.1
	${INSTALL_MAN} ${WRKSRC}/QSO.1 ${STAGEDIR}${PREFIX}/share/man/man1/QSO.1

.include <bsd.port.mk>
