# New ports collection makefile for:	gsi
# Date created:				3 October 2000
# Whom:					Sean Farley <sean-freebsd@farley.org>
#
# $FreeBSD$
#

PORTNAME=	gsi
PORTVERSION=	0.9.4
CATEGORIES=	audio
MASTER_SITES=	http://www.farley.org/ \
		http://www.xs4all.nl/~whs/gsi/bestanden/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MANCOMPRESSED=	no

MAN1=		gsifile.1 gsiplay.1
MAN3=		gsi.3 gsi_commands.3 gsi_events.3 gsif.3 gsipcm.3
MAN5=		gsi.conf.5
MAN7=		gsi_overview.7
MAN8=		gsi_server.8

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
