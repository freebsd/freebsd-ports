# New ports collection makefile for:	gsi
# Date created:				3 October 2000
# Whom:					Sean Farley <sean-freebsd@farley.org>
#
# $FreeBSD$
#

PORTNAME=	gsi
PORTVERSION=	0.9.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gsi

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	GSI - general sound interface

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MANCOMPRESSED=	no

MAN1=		gsifile.1 gsiplay.1
MAN3=		gsi.3 gsi_commands.3 gsi_events.3 gsif.3 gsipcm.3
MAN5=		gsi.conf.5
MAN7=		gsi_overview.7
MAN8=		gsi_server.8

post-patch:
.for file in lib/gsimixer/api/mixer_oss.c lib/gsimixer/api/mixer_fbsd.c \
	lib/gsipcm/api/pcm_oss.c lib/gsipcm/gsipcm.c \
	lib/gsipcm/api/pcm_fbsd.c lib/gsisynth/api/synth_oss_gus.c \
	lib/gsisynth/api/synth_oss_opl.c lib/gsisynth/api/synth_oss.c \
	lib/gsisynth/api/midi_control_oss.c
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/${file} > ${WRKSRC}/${file}.new
	@${MV} ${WRKSRC}/${file}.new ${WRKSRC}/${file}
.endfor

pre-configure:
	@${SH} ${FILESDIR}/configure.sh ${PREFIX} ${WRKSRC}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/server.conf/gsi.conf.fbsd \
		 ${PREFIX}/etc/gsi.conf.sample
.for fileNdx in gsi_server gsifile gsiplay
	@strip ${PREFIX}/bin/${fileNdx}
.endfor
.for lib in "" cd f midi_pcm mixer pcm synth
	@strip ${PREFIX}/lib/libgsi${lib}.so.[02]
.endfor
	@${ECHO} "A sample configuration file was installed as" \
		${PREFIX}/etc/gsi.conf.sample.
	@${ECHO} "Copy and edit it to fit the system."
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
