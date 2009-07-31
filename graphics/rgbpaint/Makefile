# New ports collection makefile for:	rgbpaint
# Date created:		4 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rgbpaint
PORTVERSION=	0.8.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/mtpaint

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very basic painting program

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MAN1PREFIX}/man/man1 \
		--locale=${PREFIX}/share/locale cflags slow intl man
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e '/if \[/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
