# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minivmac
PORTVERSION=	3.0.0
CATEGORIES=	emulators
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX} \
		${DISTNAME}.prj${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Miniature Macintosh emulator

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/projects/bgclx86d

USE_XORG=	x11 xext
USES=		gmake tar:tgz
CFLAGS+=	-I${LOCALBASE}/include
ALL_TARGET=	# nothing

PLIST_FILES=	bin/minivmac

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|; s|gcc|${CC}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minivmac ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
