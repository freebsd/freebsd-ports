# New ports collection makefile for:	quakeserver
# Date created:				October 26th 1996
# Whom:					jfitz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	quakeserver
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quakeworld/unix/old/ \
		ftp://ftp.idsoftware.com/idstuff/quake/
DISTFILES=	unixded-${PORTVERSION}-i386-unknown-bsdi3.0.tar.gz \
		quake106.zip

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		lha:${PORTSDIR}/archivers/lha

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
NO_CDROM=	"This software is shareware"

do-extract:
		@ ${RM} -rf ${WRKDIR}
		@ ${MKDIR} ${WRKDIR}
		@ unzip -q -o ${DISTDIR}/quake106.zip -d ${WRKDIR} resource.*
		@ ${CAT} ${WRKDIR}/resource.dat ${WRKDIR}/resource.1 > ${WRKDIR}/resource.exe
		@ cd ${WRKDIR}; lha xfq resource.exe id1/pak0.pak
		@ cd ${WRKDIR}; tar zxf ${DISTDIR}/unixded-${PORTVERSION}-i386-unknown-bsdi3.0.tar.gz

do-configure:
		@ ${CP} ${FILESDIR}/readme.port ${WRKSRC}
		@ ${CP} ${FILESDIR}/quakeserver.sh ${WRKSRC}
		@ ${CP} ${FILESDIR}/qserver.sh ${WRKSRC}
		@ ${CP} ${FILESDIR}/stopserver.sh ${WRKSRC}
		@ ${SETENV} ${MAKE_ENV} ${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/readme.port ${WRKSRC}/quakeserver.sh ${WRKSRC}/qserver.sh ${WRKSRC}/stopserver.sh

do-install:
		@ ${MKDIR} ${PREFIX}/quakeserver
		@ ${MKDIR} ${PREFIX}/quakeserver/id1
		${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak ${PREFIX}/quakeserver/id1
		${INSTALL} -c -o nobody -g nobody -m 0500 ${WRKSRC}/unixded ${PREFIX}/quakeserver
		${INSTALL_DATA} ${WRKSRC}/readme.unixded ${PREFIX}/quakeserver
		${INSTALL_DATA} ${WRKSRC}/readme.port ${PREFIX}/quakeserver
		${INSTALL_SCRIPT} -m 0750 ${WRKSRC}/quakeserver.sh ${PREFIX}/etc/rc.d
		${INSTALL} -c -o nobody -g nobody -m 0500 ${WRKSRC}/qserver.sh ${PREFIX}/quakeserver
		${INSTALL} -c -o nobody -g nobody -m 0500 ${WRKSRC}/stopserver.sh ${PREFIX}/quakeserver
		@ ${RM} -f ${PREFIX}/quakeserver/quakeserver.in
		/usr/bin/mkfifo ${PREFIX}/quakeserver/quakeserver.in
		${TOUCH} ${PREFIX}/quakeserver/quakeserver.log
		@ ${CHMOD} 700 ${PREFIX}/quakeserver/quakeserver.in ${PREFIX}/quakeserver/quakeserver.log
		@ ${CHOWN} -R nobody.nobody ${PREFIX}/quakeserver
.if !defined(BATCH)
		@ /usr/bin/more -e ${PREFIX}/quakeserver/readme.port
.endif

.include <bsd.port.mk>
