# Created by: Oleg V. Volkov <rover@lglobus.ru>
# $FreeBSD$

PORTNAME=	adom
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	http://www.adom.de/adom/download/linux/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-elf

MAINTAINER=	sr-13@mail.ru
COMMENT=	An rogue-like advanced rpg with color support (binary port)

LICENSE=	unknown
LICENSE_NAME=	The ADOM License
LICENSE_FILE=	${WRKSRC}/readme.1st
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror

NO_CDROM=	Copy of CD must be sent to author

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

WRKSRC=		${WRKDIR}/adom
NO_BUILD=	yes
STRIP=		# empty: do not strip linux binary!

.include <bsd.port.options.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/adom ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in readme.1st adomfaq.txt manual.doc
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
