# New ports collection makefile for:   tetrinet-x-1.13.16
# Date created:        11 Apr 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	tetrinet-x
PORTVERSION=	1.13.16
CATEGORIES=	games
MASTER_SITES=	http://www.giovannelli.it/~gmarco/files/ \
	     	ftp://ftp.dementia.nu/tetrinet/servers/tetrix/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	An addictive 6 player tetr*s game

WRKSRC=		${WRKDIR}/tetrinetx-${PORTVERSION}

INSTALLDIR=	${PREFIX}/tetrinet-x

do-build:
	(cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} main.c -o ../bin/tetrix.freebsd)
	(cd ${WRKSRC}/contrib/query/src && \
		${CC} ${CFLAGS} query.c -o ../../../bin/server-query)

do-install:
	${MKDIR} ${INSTALLDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/tetrinetx-1.13.16/bin/tetrix.freebsd ${INSTALLDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/tetrinetx-1.13.16/bin/server-query ${INSTALLDIR}
	${INSTALL_DATA} -m 644  ${WRKDIR}/tetrinetx-1.13.16/bin/game.conf ${INSTALLDIR}
	${INSTALL_DATA} -m 644  ${WRKDIR}/tetrinetx-1.13.16/bin/game.log ${INSTALLDIR}
	${INSTALL_DATA} -m 644  ${WRKDIR}/tetrinetx-1.13.16/bin/game.secure ${INSTALLDIR}
	${INSTALL_DATA} -m 644  ${WRKDIR}/tetrinetx-1.13.16/bin/game.winlist ${INSTALLDIR}

post-install:
	@${ECHO} ""
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/tetrinet-x.sh startup file."
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tetrinet-x.sh ${PREFIX}/etc/rc.d
	@${ECHO} ""
	@${ECHO} "Please modify configuration files located in ${INSTALLDIR}"
	@${ECHO} "before attempting to run Tetrinet server"
	@${ECHO} ""

.include <bsd.port.mk>
