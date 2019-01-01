# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	mp3gain
PORTVERSION=	1.6.2
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\./_/g}-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Tool to normalize the gain of MP3 files

LICENSE=	LGPL21

LIB_DEPENDS=	libmpg123.so:audio/mpg123

USES=		zip gmake uidfix
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/mp3gain

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3gain ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
