# Created by: Jille Timmermans (jille@quis.cx)
# $FreeBSD$

PORTNAME=	tweak
PORTVERSION=	3.02
CATEGORIES=	editors
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Efficient hex editor

PLIST_FILES=	bin/tweak \
		man/man1/tweak.1.gz

USES=		ncurses uidfix
MAKEFILE=	${FILESDIR}/Makefile.in
MAKE_ENV+=	BINDIR="${LOCALBASE}/bin" MANDIR="${PREFIX}/man/man"

.include <bsd.port.mk>
