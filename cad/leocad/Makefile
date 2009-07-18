# New ports collection makefile for:	leocad
# Date created:				27 Jan 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	leocad
PORTVERSION=	0.73
PORTREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTFILES=	leocad-${PORTVERSION:S/.p/pre/}.tgz leocad-pieces-20030330.zip
EXTRACT_ONLY=	leocad-${PORTVERSION:S/.p/pre/}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CAD program that uses bricks similar to those found in many toys

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_GL=		glut
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gtk12

post-extract:
	@${UNZIP_CMD} -q -o ${DISTDIR}/leocad-pieces-20030330.zip -d ${WRKDIR}/pieces

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/config.mk
	@cd ${WRKSRC}/linux/&&${REINPLACE_CMD} -e 's|[(]int[)]data|(intptr_t)data|'\
		dialogs.cpp dlgpiece.cpp main.cpp toolbar.cpp
	@${REINPLACE_CMD} -Ee 's|[(]int[)](.*Group)|(intptr_t)\1|'\
		${WRKSRC}/common/project.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/leocad ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pieces/* ${DATADIR}

.include <bsd.port.mk>
