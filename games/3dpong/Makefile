# New ports collection makefile for:	3dpong
# Date created:				10 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	3dpong
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/3dpong/src/ \
		ftp://ftp.billsgames.com/unix/x/3dpong/src/ \
		http://www.newbreedsoftware.com/images/prodicons/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.gif:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	X Window 3D Pong game for 1 or 2 players

LICENSE=	GPLv2

USE_XORG=	x11
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		XLIB="-L${LOCALBASE}/lib -lX11"

MAN6=		${PORTNAME}.6

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.gif \
		share/examples/${PORTNAME}/${PORTNAME}-handball.sh \
		share/examples/${PORTNAME}/${PORTNAME}-vs-computer.sh
PLIST_DIRS=	share/examples/${PORTNAME}

PORTDATA=	*
PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|cat sounds/|cat ${DATADIR}/|g' ${WRKSRC}/src/3dpong.c

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/src/${MAN6} ${MAN1PREFIX}/man/man6

# Pixmaps
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.gif ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.  endfor
.endif

# Examples
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include <bsd.port.mk>
