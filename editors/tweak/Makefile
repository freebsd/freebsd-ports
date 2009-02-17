# Ports collection makefile for:  tweak
# Date created:                   Sun Feb 15, 2009
# Whom:                           Jille Timmermans (jille@quis.cx)
# $FreeBSD$

PORTNAME=	tweak
PORTVERSION=	3.01
CATEGORIES=	editors
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/${PORTNAME}/

MAINTAINER=	jille@quis.cx
COMMENT=	An efficient hex editor

MAN1=		tweak.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/tweak

MAKEFILE=	${FILESDIR}/Makefile.in
MAKE_ENV+=	BINDIR="${LOCALBASE}/bin" MANDIR="${PREFIX}/man/man"

.include <bsd.port.mk>
