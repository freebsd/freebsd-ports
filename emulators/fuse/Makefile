# New ports collection makefile for:	fuse
# Date created:			2003-10-28
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	fuse
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	fuse-emulator

MAINTAINER=	yuri.pankov@gmail.com
COMMENT=	Free Unix (Sinclair ZX-)Spectrum Emulator

LIB_DEPENDS=	spectrum.6:${PORTSDIR}/emulators/libspectrum \
		765.4:${PORTSDIR}/emulators/lib765 \
		gcrypt.15:${PORTSDIR}/security/libgcrypt

USE_GNOME=	libxml2 glib20 gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		fuse.1

OPTIONS=	AO "Use libao for audio output" off \
		SAMPLERATE "Support for better beeper sound quality" on

.include <bsd.port.pre.mk>

.if defined(WITH_AO)
CONFIGURE_ARGS+=--with-libao
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
.endif

.if !defined(WITHOUT_SAMPLERATE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=--without-libsamplerate
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README THANKS \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
