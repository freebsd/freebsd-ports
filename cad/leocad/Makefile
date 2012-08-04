# New ports collection makefile for:	leocad
# Date created:				27 Jan 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	leocad
PORTVERSION=	0.77.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${LEOCAD_DISTNAME} ${LEOCAD_PIECES}
EXTRACT_ONLY=	${LEOCAD_DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CAD program that uses bricks similar to those found in many toys

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

LEOCAD_DISTNAME=leocad-${PORTVERSION}-src.tgz
LEOCAD_PIECES=	pieces-5823b.zip
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GL=		glut
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gtk20
MAKE_JOBS_UNSAFE=	yes

DESKTOP_ENTRIES="Leocad" "${COMMENT}" "" "${PORTNAME}" "Engineering;" "true"

PLIST_FILES=	bin/leocad \
		${DATADIR_REL}/pieces.bin \
		${DATADIR_REL}/pieces.idx
PLIST_DIRS=	${DATADIR_REL}
MAN1=		leocad.1

post-extract:
	@${UNZIP_CMD} -q -o ${DISTDIR}/${LEOCAD_PIECES} -d ${WRKDIR}/pieces

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} 's|share/man|man|g' \
		${WRKSRC}/Makefile

do-configure:
	cd ${WRKSRC} && ${GMAKE} config

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pieces/* ${DATADIR}

.include <bsd.port.mk>
