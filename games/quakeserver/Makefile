# New ports collection makefile for:	quakeserver
# Date created:				October 26th 1996
# Whom:					jfitz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	quakeserver
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sunet.se/pub/pc/games/idgames2/planetquake/threewave/unix/ \
		ftp://ftp.idsoftware.com/idstuff/quake/
DISTFILES=	unixded-${PORTVERSION}-i386-unknown-bsdi3.0.tar.gz \
		quake106.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A server to host Quake network games under FreeBSD

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip \
		lha:${PORTSDIR}/archivers/lha

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
NO_CDROM=	"This software is shareware"
USE_REINPLACE=	yes

do-extract:
		@ ${RM} -rf ${WRKDIR}
		@ ${MKDIR} ${WRKDIR}
		@ unzip -q -o ${DISTDIR}/quake106.zip -d ${WRKDIR} resource.*
		@ ${CAT} ${WRKDIR}/resource.dat ${WRKDIR}/resource.1 > ${WRKDIR}/resource.exe
		@ cd ${WRKDIR}; lha xfq resource.exe id1/pak0.pak
		@ cd ${WRKDIR}; ${TAR} zxf ${DISTDIR}/unixded-${PORTVERSION}-i386-unknown-bsdi3.0.tar.gz

do-configure:
		@ ${CP} ${FILESDIR}/readme.port ${WRKSRC}
		@ ${CP} ${FILESDIR}/quakeserver.sh ${WRKSRC}
		@ ${CP} ${FILESDIR}/qserver.sh ${WRKSRC}
		@ ${CP} ${FILESDIR}/stopserver.sh ${WRKSRC}
		@ ${SETENV} ${MAKE_ENV} ${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/readme.port ${WRKSRC}/quakeserver.sh ${WRKSRC}/qserver.sh ${WRKSRC}/stopserver.sh

pre-install:
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
		@ ${MKDIR} ${PREFIX}/quakeserver
		@ ${MKDIR} ${PREFIX}/quakeserver/id1
		${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak ${PREFIX}/quakeserver/id1
		${INSTALL} -c -g quakerun -m 0510 ${WRKSRC}/unixded ${PREFIX}/quakeserver
		${INSTALL_DATA} ${WRKSRC}/readme.unixded ${PREFIX}/quakeserver
		${INSTALL_DATA} ${WRKSRC}/readme.port ${PREFIX}/quakeserver
		${INSTALL_SCRIPT} -m 0755 ${WRKSRC}/quakeserver.sh ${PREFIX}/etc/rc.d
		${INSTALL} -c -m 0755 ${WRKSRC}/qserver.sh ${PREFIX}/quakeserver
		${INSTALL} -c -m 0755 ${WRKSRC}/stopserver.sh ${PREFIX}/quakeserver
		${TOUCH} ${PREFIX}/quakeserver/quakeserver.log
		${CHOWN} :quakerun ${PREFIX}/quakeserver/quakeserver.log
		${CHMOD} 660 ${PREFIX}/quakeserver/quakeserver.log
		@ ${RM} -f ${PREFIX}/quakeserver/quakeserver.in
		/usr/bin/mkfifo ${PREFIX}/quakeserver/quakeserver.in
		@ ${CHMOD} 660 ${PREFIX}/quakeserver/quakeserver.in
		@ ${CHOWN} :quakerun ${PREFIX}/quakeserver/quakeserver.in

.include <bsd.port.mk>
