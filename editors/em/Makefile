# New ports collection makefile for:	MicroEmacs/PK-TOY 4.0.16
# Date created:         27 Jan 2001
# Whom:                 Tadashi Yumoto
#
# $FreeBSD$
#

PORTNAME=	em
PORTVERSION=	4.0.16
CATEGORIES=	editors
MASTER_SITES=	http://www3.famille.ne.jp/~ncc1701/em/
DISTNAME=	em-4.0.16-lt

MAINTAINER=	ports@FreeBSD.org

post-install:
	strip ${PREFIX}/bin/em

.include <bsd.port.mk>
