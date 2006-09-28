# New ports collection makefile for:    wolfpack
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	wolfpack
PORTVERSION=	4.2.21
CATEGORIES=	games
MASTER_SITES=	http://www.wolfpackempire.com/Downloads/server/ \
		http://empire.gletsjer.net/Downloads/server/ \
		http://www.wolfpackempire.com/Downloads/server/oldversions/ \
		http://empire.gletsjer.net/Downloads/server/oldversions/
DISTNAME=	empire-${PORTVERSION}

MAINTAINER=	johans@stack.nl
COMMENT=	Long term multiplayer strategy game

.if !defined(BATCH)
IS_INTERACTIVE=	yes     # configure script asks questions
.endif
ALL_TARGET=	freebsd

USE_RC_SUBR=	wolfpack

MAN1=		fairland.1 files.1 pconfig.1
MAN6=		emp_client.6 emp_server.6

MAKE_ARGS=	PREFIX=${PREFIX}

.include <bsd.port.pre.mk>

PKGDEINSTALL=	${PKGINSTALL}

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

pre-configure:
	${MKDIR} ${WRKSRC}/data

pre-install:
	${MKDIR} ${PREFIX}/wolfpack
	${MKDIR} ${PREFIX}/wolfpack/data
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	${CHMOD} 750 ${PREFIX}/wolfpack/data
	${TAR} -C ${WRKSRC} -cf - info.nr scripts doc | ${TAR} -C ${PREFIX}/wolfpack -xf -
	${CHMOD} 755 ${PREFIX}/wolfpack/info.nr
	${CHMOD} 644 ${PREFIX}/wolfpack/info.nr/*
	${CHOWN} -R root:wheel ${PREFIX}/wolfpack
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/wolfpack
	${INSTALL_MAN} ${WRKSRC}/man/fairland.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/files.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/pconfig.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/emp_client.6 ${PREFIX}/man/man6/
	${INSTALL_MAN} ${WRKSRC}/man/emp_server.6 ${PREFIX}/man/man6/
	@${CAT} ${FILESDIR}/post-install-info
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.post.mk>
