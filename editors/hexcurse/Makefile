PORTNAME=	hexcurse
DISTVERSIONPREFIX=	v
DISTVERSION=	1.60.0
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Versatile ncurses-based hex editor
WWW=		https://BSDforge.com/projects/editors/hexcurse/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	LonnyGomes

GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-error=deprecated-non-prototype

PLIST_FILES=	bin/hexcurse share/man/man1/hexcurse.1.gz

.include <bsd.port.mk>
