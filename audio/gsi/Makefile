# New ports collection makefile for:	gsi
# Date created:				3 October 2000
# Whom:					Sean Farley <sean-freebsd@farley.org>
#
# $FreeBSD$
#

PORTNAME=	gsi
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/GSI%20Current/v${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	General sound interface

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" MYFLAGS="${CFLAGS}" OPTIMIZE=""
USE_LDCONFIG=	yes

MANCOMPRESSED=	no

MAN1=		gsifile.1 gsiplay.1
MAN3=		gsi.3 gsi_commands.3 gsi_events.3 gsif.3 gsipcm.3
MAN5=		gsi.conf.5
MAN7=		gsi_overview.7
MAN8=		gsi_server.8

post-extract:
	@${RM} -f ${WRKSRC}/lib/include/gsi/gsisynth.h

post-patch:
.for f in lib/device/gsimixer/api/mixer_fbsd.c \
	lib/device/gsipcm/api/pcm_fbsd.c
	@${REINPLACE_CMD} -e \
		's|machine/soundcard.h|sys/soundcard.h|g' ${WRKSRC}/${f}
.endfor
.for f in server/FINISH_host_allow.c server/client.c server/conf.c
	@${REINPLACE_CMD} -e \
		's|"/etc/|"${PREFIX}/etc/|g' ${WRKSRC}/${f}
.endfor

do-configure:
	@${SH} ${FILESDIR}/configure.sh ${PREFIX} ${WRKSRC}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/server/conf/gsi.conf.fbsd \
		 ${PREFIX}/etc/gsi.conf.sample
.for fileNdx in gsi_server gsifile gsiplay
	@${STRIP_CMD} ${PREFIX}/bin/${fileNdx}
.endfor
	@${ECHO_MSG} "A sample configuration file was installed as" \
		${PREFIX}/etc/gsi.conf.sample.
	@${ECHO_MSG} "Copy and edit it to fit the system."
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
