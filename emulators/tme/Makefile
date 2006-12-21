# New ports collection makefile for:	tme
# Date created:		2006-12-14
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	tme
PORTVERSION=	0.4
CATEGORIES=	emulators
MASTER_SITES=	http://theory.lcs.mit.edu/~fredette/tme/

MAINTAINER=	trasz@pin.if.uz.zgora.pl
COMMENT=	Emulator for Sun 2/120 and Sun 3/150 machines

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12 gnometarget
CONFIGURE_ARGS+=	--disable-shared
MAKE_ENV=	LANG=C

post-patch:
		${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/libtme/module.c

.include <bsd.port.mk>
