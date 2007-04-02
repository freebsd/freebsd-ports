# New ports collection makefile for:	hinversi
# Date created:		2 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hinversi
PORTVERSION=	0.8.1
CATEGORIES=	games
MASTER_SITES=	http://asturio.gmxhome.de/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Reversi/Othello clone

USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --mandir=${PREFIX}/man\
		--disable-static
MAN1=	hinversi-cli.1

post-patch:
	@${REINPLACE_CMD} -e '/^mkdir_p/s|=.*|=$$(mkinstalldirs)|'\
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|=.*|=${PREFIX}/libdata/pkgconfig|'\
		${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
