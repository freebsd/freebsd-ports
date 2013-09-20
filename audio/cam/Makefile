# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	cam
PORTVERSION=	1.02
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cpu's Audio Mixer [curses based]

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		BINDIR="${PREFIX}/bin" \
		MANDIR="${MAN1PREFIX}/man/man1" \
		XEFILE=""

NO_STAGE=	yes
MAN1=		cam.1
PLIST_FILES=	bin/cam

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cam ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cam.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
