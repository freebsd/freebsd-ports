# New ports collection makefile for:	frodo
# Version required:	4.1
# Date created:		11 Dez 1997
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.3 1998/08/05 09:30:49 asami Exp $

DISTNAME=	FrodoV4_1a.Src
PKGNAME=	frodo-4.1
CATEGORIES=	emulators tk80
MASTER_SITES=	ftp://sunsite.unc.edu/pub/micro/commodore/crossplatform/emulators/unix/

MAINTAINER=	dirk.meyer@dinoex.sub.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

USE_X_PREFIX=	YES
ALL_TARGET=	Frodo
WRKSRC=		${WRKDIR}/Frodo/Src

ROM=		1541 Basic Char Kernal

do-configure:
	@(cd ${WRKSRC}; ${SH} ./configure)

do-install:
	${SED} -e 's/\$${PREFIX}/${PREFIX:S/\//\\\//g}/g' \
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
	@cd ${WRKDIR}/Frodo/64prgs; tar cf - . | (cd ${PREFIX}/libexec/frodo/64prgs; tar xf -)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/frodo
.for i in CHANGES
	${INSTALL_DATA} ${WRKDIR}/Frodo/${i} ${PREFIX}/share/doc/frodo
.endfor
	@cd ${WRKDIR}/Frodo/Docs; tar cf - . | (cd ${PREFIX}/share/doc/frodo; tar xf -)
.endif

.include <bsd.port.mk>
