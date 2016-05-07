# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	a2png
PORTVERSION=	0.1.5
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts plain ASCII text into PNG bitmap images

LIB_DEPENDS=	libgd.so:graphics/gd

USES=	tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gd
CFLAGS+=	-DDEFAULT_FONTPATH='\"${FONTROOTDIR}/TTF:${FONTROOTDIR}/Type1:${FONTROOTDIR}\"'
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

FONTROOTDIR?=	${LOCALBASE}/share/fonts

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
