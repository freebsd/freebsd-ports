PORTNAME=	chexedit
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	https://www.rogoyski.com/adam/programs/hexedit/ \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	hexedit-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Full screen text mode Hex editor using the [n]curses library
WWW=		https://www.rogoyski.com/adam/programs/hexedit/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_ncurses_h=yes
PLIST_FILES=	bin/chexedit \
		share/man/man1/chexedit.1.gz

# Fix build on recent current
CFLAGS+=	-fcommon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hexedit ${STAGEDIR}${PREFIX}/bin/chexedit
	${INSTALL_MAN} ${WRKSRC}/docs/hexedit.1 ${STAGEDIR}${PREFIX}/share/man/man1/chexedit.1

.include <bsd.port.mk>
