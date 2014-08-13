# Created by: Oleg V. Volkov <rover@lglobus.ru>
# $FreeBSD: head/games/adom/Makefile 351718 2014-04-21 21:15:57Z pawel $

PORTNAME=	adom
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	games linux
MASTER_SITES=	http://www.adom.de/adom/download/linux/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-elf

MAINTAINER=	sr-13@mail.ru
COMMENT=	Rogue-like advanced rpg with color support (binary port)

LICENSE=	unknown
LICENSE_NAME=	The ADOM License
LICENSE_FILE=	${WRKSRC}/readme.1st
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror

NO_CDROM=	Copy of CD must be sent to author

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	ncurses-base xorglibs

WRKSRC=		${WRKDIR}/adom
NO_BUILD=	yes
STRIP=		# empty: do not strip linux binary!

SUB_FILES=	pkg-message

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/adom ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in readme.1st adomfaq.txt manual.doc
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
