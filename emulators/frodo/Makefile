# New ports collection makefile for:	frodo
# Date created:		11 Dez 1997
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	frodo
PORTVERSION=	4.1a
CATEGORIES=	emulators tk83
MASTER_SITES=	ftp://metalab.unc.edu/pub/micro/commodore/crossplatform/emulators/Frodo/ \
		ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/Frodo/
DISTNAME=	FrodoV4_1a.Src

MAINTAINER=	dinoex@FreeBSD.org

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

USE_X_PREFIX=	yes
ALL_TARGET=	Frodo
WRKSRC=		${WRKDIR}/Frodo/Src

ROM=		1541 Basic Char Kernal

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKDIR}/Frodo/TkGui.tcl

do-configure:
	@(cd ${WRKSRC}; ${SH} ./configure)

do-install:
	${SED} -e 's=\$${PREFIX}=${PREFIX}=g' \
		 < ${FILESDIR}/frodo > ${WRKDIR}/frodo
	${INSTALL_SCRIPT} ${WRKDIR}/frodo ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/frodo
	${INSTALL_PROGRAM} ${WRKDIR}/Frodo/Frodo ${PREFIX}/libexec/frodo
.for i in ${ROM}
	${INSTALL_DATA} "${WRKDIR}/Frodo/${i} ROM" ${PREFIX}/libexec/frodo
.endfor
	${INSTALL_DATA} "${WRKDIR}/Frodo/Frodo Logo" ${PREFIX}/libexec/frodo
	${CP} "${WRKDIR}/Frodo/TkGui.tcl" ${PREFIX}/libexec/frodo
	${MKDIR} ${PREFIX}/libexec/frodo/64prgs
	@${TAR} -C ${WRKDIR}/Frodo/64prgs -cf - . | \
		${TAR} -C ${PREFIX}/libexec/frodo/64prgs -xf -

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in CHANGES
	${INSTALL_DATA} ${WRKDIR}/Frodo/${i} ${DOCSDIR}/
.endfor
	@${TAR} -C ${WRKDIR}/Frodo/Docs -cf - . | ${TAR} -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
