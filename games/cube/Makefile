# New ports collection makefile for:	cube
# Date created:        17 October 2002
# Whom:                Arjan van Leeuwen
#
# $FreeBSD$
#

PORTNAME=	cube
PORTVERSION=	2005.08.29
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${CUBE_DATA} ${CUBE_SRC}
EXTRACT_ONLY=	${CUBE_SRC}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	An OpenGL 3D First Person Shooter game

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ACLOCAL=true AUTOCONF=true AUTOMAKE=true
CONFIGURE_WRKSRC=	${WRKSRC}/../enet
WRKSRC=		${WRKDIR}/${PORTNAME}_source/src
ALL_TARGET=	enet

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on

SUB_FILES=	cube_client cube_server

CUBE_DATA=	${PORTNAME}_${PORTVERSION:S/./_/g}_unix.tar.gz
CUBE_SRC=	${PORTNAME}_${PORTVERSION:S/./_/g}_src.zip

.include <bsd.port.pre.mk>

.if !defined(WITH_CLIENT) && !defined(WITH_DEDICATED)
IGNORE=		needs at least one executable (CLIENT and DEDICATED)
.endif

.if defined(WITH_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
CUBE_BIN+=	client
.else
PLIST_SUB+=	CLIENT=""
.endif

.if defined(WITH_DEDICATED)
ALL_TARGET+=	server
PLIST_SUB+=	DEDICATED=""
CUBE_BIN+=	server
.else
PLIST_SUB+=	DEDICATED=""
.endif

post-extract:
	@${TAR} zxf ${DISTDIR}/${CUBE_DATA} -C ${WRKDIR}

pre-configure:
	@${CHMOD} u+x ${CONFIGURE_WRKSRC}/configure

do-install:
.for f in ${CUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/cube_${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cube_${f} ${PREFIX}/libexec
.endfor
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKDIR}/cube/data ${WRKDIR}/cube/packages ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/cube/autoexec.cfg ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cube/readme.html ${DOCSDIR}
	${CP} -R ${WRKDIR}/cube/docs ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
