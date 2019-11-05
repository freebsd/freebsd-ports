# Created by: proff@iq.org
# $FreeBSD$

PORTNAME=	xmountains
PORTVERSION=	2.9
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.uwsg.indiana.edu/linux/debian/pool/main/x/xmountains/ \
		ftp://ftp.fi.netbsd.org/.m/mirrors1/archive.ubuntu.com/pool/universe/x/xmountains/ \
		ftp://ftp.mirrorservice.org/sites/archive.raspbian.org/raspbian/pool/main/x/xmountains/ \
		ftp://ftp.unicamp.br/pub/debian/pool/main/x/xmountains/ \
		ftp://ftp.debian.com/debian/pool/main/x/xmountains/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ak@FreeBSD.org
COMMENT=	X11 based fractal landscape generator

NO_WRKSUBDIR=	yes

USES=		xorg
USE_XORG=	xbitmaps x11

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-extract:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/${PORTNAME}.6

do-build:
	(cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} *.c -lX11 -lm -o ${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
