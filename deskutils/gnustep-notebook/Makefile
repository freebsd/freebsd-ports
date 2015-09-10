# $FreeBSD$

PORTNAME=	notebook
PORTVERSION=	0.3
PORTREVISION=	5
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://notebook.cowgar.com/NoteBook/releases/ \
		http://io.debian.net/~tar/debian/notebook/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	NoteBook-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Place to store notes in an organized manner

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/NoteBook.app/NoteBook

.include <bsd.port.mk>
