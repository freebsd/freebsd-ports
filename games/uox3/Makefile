# New ports collection makefile for:    uox3
# Date created:         24 Feb 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uox3
PORTVERSION=	0.69.02
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.mwcyber.com/GateTraveler/uox/files/:file1 \
		http://mirror.etf.bg.ac.yu/freebsd/distfiles/uox3/:file2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:file1 tqpsworld${EXTRACT_SUFX}:file2
DISTNAME=	uox3v6902-linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GPL'd server for Origin Systems' Ultima Online multiplayer game

DIST_SUBDIR=	uox3
USE_ZIP=	YES
NO_WRKSUBDIR=	YES
PATCH_STRIP=	-p1

USE_GMAKE=	YES
MAKEFILE=	makefile
ALL_TARGET=	linux

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

do-build:
	cd ${WRKSRC}/dev && ${GMAKE} -f ${MAKEFILE} CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" ${ALL_TARGET}

do-install:
	-${RM} ${WRKDIR}/uox/uox3.ini.orig
	${MKDIR} ${PREFIX}/uox3
	for FILE in ${WRKDIR}/uox/* ; do \
		${INSTALL_DATA} $${FILE} ${PREFIX}/uox3 ;\
	done
	${INSTALL_PROGRAM} ${WRKSRC}/dev/uox3 ${PREFIX}/uox3
	${INSTALL_DATA} ${WRKDIR}/uox3.wsc ${PREFIX}/uox3
	${INSTALL_DATA} ${WRKDIR}/WSC\ Changes.txt ${PREFIX}/uox3/wsc_changes.txt
	${INSTALL_SCRIPT} ${FILESDIR}/uox3.sh ${PREFIX}/etc/rc.d/uox3.sh
.ifdef NOPORTDOCS
	@${ECHO_MSG} "==> Extra documentation WILL NOT be installed."
.else
	@${ECHO_MSG} "==> Installing extra documentation..."
	${MKDIR} ${PREFIX}/uox3/docs
	for FILE in ${WRKDIR}/docs/* ; do \
		${INSTALL_DATA} $${FILE} ${PREFIX}/uox3/docs ;\
	done
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
