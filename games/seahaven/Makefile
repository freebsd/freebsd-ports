# Created by: imp
# $FreeBSD$

PORTNAME=	seahaven
PORTVERSION=	1.60
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://seahaven.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imp@FreeBSD.org
COMMENT=	The classic, lightweight version of Seahaven Towers

GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xft
PLIST_FILES=	bin/seahaven man/man6/seahaven.6.gz
MAKE_ARGS=	bindir=${STAGEDIR}${PREFIX}/bin mandir=${STAGEDIR}${PREFIX}/man

.include <bsd.port.mk>
