# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	libspectrum
PORTVERSION=	1.1.1
CATEGORIES=	emulators devel
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Handling of ZX-Spectrum emulator files formats

LICENSE=	GPLv2

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		gmake pkgconfig

MAN3=		libspectrum.3

OPTIONS_DEFINE=	AUDIOFILE
AUDIOFILE_DESC=	Support loading from .wav files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUDIOFILE}
LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=--without-libaudiofile
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} \
		AUTHORS ChangeLog README THANKS doc/libspectrum.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
