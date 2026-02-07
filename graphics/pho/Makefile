PORTNAME=	pho
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${WWW}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight image viewer
WWW=		https://shallowsky.com/software/pho/

LICENSE=	GPLv2

USES=		gmake gnome pkgconfig
USE_GNOME=	gtk20
ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -g -O2 ||' ${WRKSRC}/exif/Makefile

.include <bsd.port.mk>
