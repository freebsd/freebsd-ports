# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	icbm3d
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/icbm3d/  \
		ftp://ftp.billsgames.com/unix/x/icbm3d/ \
		http://www.newbreedsoftware.com/images/prodicons/:icons
DISTFILES=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.gif:icons
EXTRACT_ONLY=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Inter-Continental Ballistic Missiles, 3D

WRKSRC=		${WRKDIR}/icbm3d

USE_XORG=	x11
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.gif

PORTDOCS=	README.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Pixmaps
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.gif ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
