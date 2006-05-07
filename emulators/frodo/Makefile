# New ports collection makefile for:	frodo
# Date created:		11 Dez 1997
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	frodo
PORTVERSION=	4.1b
PORTREVISION=	3
CATEGORIES=	emulators tk84
MASTER_SITES=	http://frodo.cebix.net/downloads/
DISTNAME=	FrodoV4_1b.Src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulates a Commodore 64

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_X_PREFIX=	yes
ALL_TARGET=	Frodo
WRKNAME=	Frodo-4.1b
WRKSRC=		${WRKDIR}/${WRKNAME}/Src
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
.endif

ROM=		1541 Basic Char Kernal

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKDIR}/${WRKNAME}/TkGui.tcl
.if !defined(WITHOUT_SDL)
	${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|g" \
		${WRKSRC}/configure
.endif

do-install:
	${SED} -e 's=\$${PREFIX}=${PREFIX}=g' \
		 < ${FILESDIR}/frodo > ${WRKDIR}/frodo
	${INSTALL_SCRIPT} ${WRKDIR}/frodo ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/frodo
	${INSTALL_PROGRAM} ${WRKDIR}/${WRKNAME}/Frodo ${PREFIX}/libexec/frodo
.for i in ${ROM}
	${INSTALL_DATA} "${WRKDIR}/${WRKNAME}/${i} ROM" ${PREFIX}/libexec/frodo
.endfor
	${INSTALL_DATA} "${WRKDIR}/${WRKNAME}/Frodo Logo" ${PREFIX}/libexec/frodo
	${INSTALL_SCRIPT} "${WRKDIR}/${WRKNAME}/TkGui.tcl" ${PREFIX}/libexec/frodo
	${MKDIR} ${PREFIX}/libexec/frodo/64prgs
	@${TAR} -C ${WRKDIR}/${WRKNAME}/64prgs -cf - . | \
		${TAR} -C ${PREFIX}/libexec/frodo/64prgs -xf -

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in CHANGES
	${INSTALL_DATA} ${WRKDIR}/${WRKNAME}/${i} ${DOCSDIR}/
.endfor
	@${TAR} -C ${WRKDIR}/${WRKNAME}/Docs -cf - . | ${TAR} -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
