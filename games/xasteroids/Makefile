PORTNAME=	xasteroids
PORTVERSION=	5.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.sh.Z

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	X11 based asteroids style arcade game

LICENSE=	XASTEROIDS
LICENSE_NAME=	Xasteroids license
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		localbase:ldflags xorg
USE_XORG=	x11 xext

LIBS+=		-lXext -lX11 -lm
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/xasteroids \
		share/man/man6/xasteroids.6.gz

do-extract:
	(cd ${EXTRACT_WRKDIR} && \
	    ${SETENV} ${EXTRACT_ENV} zcat ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
	    ${SETENV} ${EXTRACT_ENV} ${SH} -s)

do-build:
	(cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} \
	    -o xasteroids xast.c ${LIBS})

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xasteroids ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} xast.man ${STAGEDIR}${PREFIX}/share/man/man6/xasteroids.6)

.include <bsd.port.mk>
