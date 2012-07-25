# New ports collection makefile for:	tme
# Date created:		2006-12-14
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	tme
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://people.csail.mit.edu/fredette/tme/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for Sun 2/120, 3/150, and SPARCstation 2 machines

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	x11
USE_GNOME=	gtk12
CONFIGURE_ARGS+=	--disable-shared
MAKE_ENV=	LANG=C
MAKE_JOBS_UNSAFE=	yes

post-patch:
		${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/libtme/module.c

.include <bsd.port.mk>
