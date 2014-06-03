# Created by: greg
# $FreeBSD$

PORTNAME=	wavplay
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A wav player and recorder

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=Doesn't work on !i386 and amd64

INSTALL_TARGET=	install PREFIX="${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/wavplay bin/wavrec man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|u_long|u_int|g' ${WRKSRC}/*.c ${WRKSRC}/*.h

.include <bsd.port.mk>
