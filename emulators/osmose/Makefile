# New ports collection makefile for:	osmose
# Date created:				27 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	osmose
PORTVERSION=	0.9.96
CATEGORIES=	emulators
MASTER_SITES=	http://bcz.asterope.fr/osmose/
DISTNAME=	Osmose-${PORTVERSION:S/./-/g}-QT

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sega Master System emulator

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl moc_build qmake_build uic_build
QMAKEFLAGS+=	TARGET=release

PORTDOCS=	Readme.txt TODO.txt
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
