# Created by: Oleg V. Volkov <rover@lglobus.ru>
# $FreeBSD$

PORTNAME=	adom
PORTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	games linux
MASTER_SITES=	http://www.adom.de/adom/download/linux/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-elf

MAINTAINER=	sr-13@mail.ru
COMMENT=	Rogue-like advanced rpg with color support (binary port)

BROKEN=		unfetchable

LICENSE=	unknown
LICENSE_NAME=	The ADOM License
LICENSE_FILE=	${WRKSRC}/readme.1st
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror

NO_CDROM=	Copy of CD must be sent to author

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386 amd64
USES=		linux
USE_LINUX=	xorglibs

WRKSRC=		${WRKDIR}/adom
NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adom ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in readme.1st adomfaq.txt manual.doc
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
