# New ports collection makefile for:	trommler
# Date created:				17 Apr 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	trommler
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://muth.org/Robert/Trommler/
DISTNAME=	trommler.3.4

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A GTK based drum machine

WRKSRC=		${WRKDIR}/Trommler

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
#the third Makefile edit replaces the contents
#of a comment so CC can be respected
	@${REINPLACE_CMD} -e \
		's|-O9|${CFLAGS}|; \
		s|-Werror||; \
		s|^# Makefile|CC=${CC}|' \
		${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e \
		's|"/Drums"|"${PREFIX}/share/trommler/Drums"|' \
		${WRKSRC}/gui.c

pre-build:
#remove stale linux binaries
	@${RM} ${WRKSRC}/playsample ${WRKSRC}/wav2smp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/playsample ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/trommler ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/wav2smp ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/trommler/Drums
	@${MKDIR} ${PREFIX}/share/trommler/Songs
	@${INSTALL_DATA} ${WRKSRC}/Drums/*.smp ${PREFIX}/share/trommler/Drums
	@${INSTALL_DATA} ${WRKSRC}/Songs/*.sng ${PREFIX}/share/trommler/Songs

.include <bsd.port.mk>
