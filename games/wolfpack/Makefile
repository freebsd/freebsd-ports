# New ports collection makefile for:    wolfpack
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	wolfpack
PORTVERSION=	4.2.12
CATEGORIES=	games
MASTER_SITES=	http://www.empire.cx/Downloads/server/ \
		http://www.empire.cx/Downloads/server/oldversions/
DISTNAME=	empire${PORTVERSION}

MAINTAINER=	darius@dons.net.au
COMMENT=	Long term multiplayer strategy game

.if !defined(BATCH)
IS_INTERACTIVE=	yes     # configure script asks questions
.endif
WRKSRC=		${WRKDIR}/emp4
ALL_TARGET=	freebsd

MAN1=		fairland.1 files.1 land.1 ore.1 pconfig.1 perfect.1
MAN6=		emp_client.6 emp_server.6

MAKE_ARGS=	PREFIX=${PREFIX}

pre-install:
	${MKDIR} ${PREFIX}/wolfpack
	${MKDIR} ${PREFIX}/wolfpack/data

post-install:
	${CHMOD} 750 ${PREFIX}/wolfpack/data
	${TAR} -C ${WRKDIR}/emp4 -cf - info.nr scripts doc | ${TAR} -C ${PREFIX}/wolfpack -xf -
	${CHMOD} 755 ${PREFIX}/wolfpack/info.nr
	${CHMOD} 644 ${PREFIX}/wolfpack/info.nr/*
	${CHOWN} -R root:wheel ${PREFIX}/wolfpack
	${INSTALL_DATA} ${WRKDIR}/emp4/README ${PREFIX}/wolfpack
	${INSTALL_MAN} ${WRKDIR}/emp4/man/fairland.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/emp4/man/files.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/emp4/man/land.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/emp4/man/ore.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/emp4/man/pconfig.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/emp4/man/perfect.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/emp4/man/emp_client.6 ${PREFIX}/man/man6/
	${INSTALL_MAN} ${WRKDIR}/emp4/man/emp_server.6 ${PREFIX}/man/man6/
	@${CAT} ${FILESDIR}/post-install-info

.include <bsd.port.mk>
