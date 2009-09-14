# New ports collection makefile for:	World of Goo (Linux demo version)
# Date created:				14 Sep 2009
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	worldofgoo
PORTVERSION=	1.41
CATEGORIES=	games linux
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/
PKGNAMEPREFIX=	linux-
DISTNAME=	WorldOfGooDemo.${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Demo version of incredible physics based puzzle/construction game

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	yes
USE_LINUX_APPS=	libglu libvorbis mikmod sdl12 sdlmixer
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/WorldOfGooDemo
DATADIR=	${PREFIX}/share/WorldOfGoo
DOCSDIR=	${PREFIX}/share/doc/WorldOfGoo

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
TARGET_BIN=	WorldOfGoo.bin32
.else
TARGET_BIN=	WorldOfGoo.bin64
.endif

# Data files are in pkg-plist
PLIST_FILES=	bin/WorldOfGoo bin/${TARGET_BIN}
PORTDOCS=	eula.txt linux-issues.txt readme.html

pre-patch: .SILENT
# Wrapper script is required since game binary looks for its resources in
# current directory only.  Vendor provided one is overly complicated, so
# we create our own, without blackjack and hookers.
	${MV} ${WRKSRC}/WorldOfGoo ${WRKSRC}/WorldOfGoo.vendor
	${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/WorldOfGoo
	${ECHO_CMD} "" >> ${WRKSRC}/WorldOfGoo
	${ECHO_CMD} "cd ${DATADIR} && ${PREFIX}/bin/${TARGET_BIN}" \
		>> ${WRKSRC}/WorldOfGoo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${TARGET_BIN} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/WorldOfGoo ${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "properties res" ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
