# New ports collection makefile for:	Rollemup
# Date created:		22 October 1999
# Whom:			Kazuki Sakamoto <sakamoto@netbsd.org>
#
# $FreeBSD$
# $NetBSD: Makefile,v 1.4 1999/11/23 16:54:40 hubertf Exp $
#

PORTNAME=	rollemup
PORTVERSION=	1.0
CATEGORIES=	games linux
MASTER_SITES=	http://usa.lostboys.nl/medialab/rollemup/Linux/
DISTNAME=	Rollemup

MAINTAINER=	sanpei@FreeBSD.org

BROKEN=		"Does not fetch"

LICENSE=	no-commercial-use
RESTRICTED=	You are not allowed to distribute the software by any means. \
		You are allowed to download a copy from this site for personal use. \
		See http://www.medialab.lostboys.nl/content/showcase/license.html

ONLY_FOR_ARCHS= i386

USE_LINUX=	yes

EXTRACT_ONLY=	# empty
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

PLIST=		${WRKDIR}/PLIST
PLIST_SRC=	${PLIST}
PKGMESSAGE=	${WRKDIR}/MESSAGE
GAMES_DIR=	lib

do-build:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' -e 's|$${GAMES_DIR}|${GAMES_DIR}|g' ${FILESDIR}/rollemup.sh \
		> ${WRKDIR}/rollemup
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' -e 's|$${GAMES_DIR}|${GAMES_DIR}|g' ${FILESDIR}/MESSAGE \
		> ${PKGMESSAGE}
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' ${FILESDIR}/README.Rollemup \
		> ${WRKDIR}/README.Rollemup

do-install:
	@${MKDIR} ${PREFIX}/${GAMES_DIR}
	@${TAR} xCzf ${PREFIX}/${GAMES_DIR} ${_DISTDIR}/${DISTFILES}
	@${TOUCH} ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup.ini
	@${MV} ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/rollemup ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKDIR}/README.Rollemup \
		${PREFIX}/${GAMES_DIR}/Rollemup
	@${CP} ${PKGDIR}/pkg-plist ${PLIST_SRC}
	@(cd ${PREFIX}; \
	  find ${GAMES_DIR}/Rollemup -type f >> ${PLIST_SRC}; \
	  for DIR in `find ${GAMES_DIR}/Rollemup -type d | sort -r`; do \
	    ${ECHO_CMD} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)
	@${CHOWN} root:games ${PREFIX}/bin/Rollemup
	@${CHMOD} 2755 ${PREFIX}/bin/Rollemup
	@${CHOWN} -R root:games ${PREFIX}/${GAMES_DIR}/Rollemup
	@${CHMOD} 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Games
	@${CHMOD} 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Upload
	@${CHMOD} 664 ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup.ini

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
