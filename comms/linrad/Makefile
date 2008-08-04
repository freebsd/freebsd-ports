# ports collection makefile for:	linrad
# Date created:		7 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	linrad
PORTVERSION=	2.49
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.nitehawk.com/sm5bsz/linuxdsp/archive/\
		http://g7rau.demon.co.uk/sm5bsz/linuxdsp/archive/\
		http://www.sm5bsz.com/linuxdsp/archive/
DISTNAME=	lir02-49
EXTRACT_SUFX=	.tbz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio DSP utility (SDR)

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${PORTNAME}-0${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}
USE_GMAKE=	yes
USE_BZIP2=	yes
ALL_TARGET=	xlinrad
USE_XORG=	x11
ONLY_FOR_ARCHS=	i386
LINRAD_DOCFILES=	z_APM.txt z_BUFFERS.txt z_CALIBRATE.txt \
			z_COPYRIGHT.txt z_GIFINFO.txt \
			z_MOUSE.txt z_NETWORK.txt \
			z_PARALLEL_PORT.txt z_SETTINGS.txt \
			z_USERS_EXTRA.txt z_USERS_HWARE.txt

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	-e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}/|' \
		${WRKSRC}/help.c

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/errors.lir ${DATADIR}/errors.lir
	${INSTALL_DATA} ${WRKSRC}/help.lir ${DATADIR}/help.lir
	${INSTALL_SCRIPT} -m04555 ${FILESDIR}/linrad ${PREFIX}/bin/linrad
# Some day we may want the svga version as well.
#	${INSTALL_PROGRAM} -m04555 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}.svga
	${INSTALL_PROGRAM} -m04555 ${WRKSRC}/x${PORTNAME} ${PREFIX}/bin/x${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${LINRAD_DOCFILES}
	@${INSTALL_DATA}  ${WRKSRC}/$f ${DOCSDIR}/$f
.endfor
	@${ECHO} ""
	@${ECHO} "linrad docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
