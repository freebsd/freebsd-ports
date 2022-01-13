# Created by: greg

PORTNAME=	wavplay
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Wav player and recorder

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	does not play sound correctly

CFLAGS+=	-D_WANT_SEMUN

INSTALL_TARGET=	install PREFIX="${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/wavplay bin/wavrec man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|u_long|u_int|g' ${WRKSRC}/*.c ${WRKSRC}/*.h

.include <bsd.port.mk>
