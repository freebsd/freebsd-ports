# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	a2png
PORTVERSION=	0.1.5
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts plain ASCII text into PNG bitmap images

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		tar:bzip2 localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gd
CFLAGS+=	-DDEFAULT_FONTPATH='\"${FONTROOTDIR}/TTF:${FONTROOTDIR}/Type1:${FONTROOTDIR}\"'
BINARY_ALIAS=	gdlib-config=true
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

FONTROOTDIR?=	${LOCALBASE}/share/fonts

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
