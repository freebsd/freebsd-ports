# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	worldofgoo
PORTVERSION=	1.41
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/
PKGNAMEPREFIX=	linux-
DISTNAME=	WorldOfGooDemo.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Demo version of incredible physics based puzzle/construction game

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	yes
USE_LINUX_APPS=	libvorbis mikmod sdl12 sdlmixer
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/WorldOfGooDemo
DATADIR=	${PREFIX}/share/WorldOfGoo
DOCSDIR=	${PREFIX}/share/doc/WorldOfGoo

OPTIONS_DEFINE=	DOCS

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
USE_LINUX_APPS+=	libglu
.else
USE_LINUX_APPS+=	dri
.endif

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
	${INSTALL_PROGRAM} ${WRKSRC}/${TARGET_BIN} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/WorldOfGoo ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "properties res" ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
