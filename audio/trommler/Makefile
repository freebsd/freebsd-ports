# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	trommler
PORTVERSION=	3.8
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://muth.org/Robert/Trommler/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+2 based drum machine

LICENSE=	GPLv2

USES=		gmake pkgconfig python:2.7,build shebangfix
SHEBANG_FILES=	genexport.py
USE_GNOME=	gtk20

WRKSRC=		${WRKDIR}/Trommler

post-patch:
# The third edit replaces the contents of a comment, so CC can be respected
	@${REINPLACE_CMD} -e 's|-O9|${CFLAGS}| ; s|-Werror|| ; \
		s|^# Makefile|CC=${CC}|' ${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e 's|"/Drums"|"${PREFIX}/share/trommler/Drums"|' \
		${WRKSRC}/gui.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/playsample ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trommler ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wav2smp ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/trommler/Drums
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/trommler/Songs
	${INSTALL_DATA} ${WRKSRC}/Drums/*.smp ${STAGEDIR}${PREFIX}/share/trommler/Drums
	${INSTALL_DATA} ${WRKSRC}/Songs/*.sng ${STAGEDIR}${PREFIX}/share/trommler/Songs

.include <bsd.port.mk>
