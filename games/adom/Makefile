# Created by: Oleg V. Volkov <rover@lglobus.ru>
# $FreeBSD$

PORTNAME=	adom
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://www.adom.de/adom/download/linux/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-elf

MAINTAINER=	sr-13@mail.ru
COMMENT=	An rogue-like advanced rpg with color support (binary port)

LICENSE=	unknown
LICENSE_NAME=	The ADOM License
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror
LICENSE_FILE=	${WRKSRC}/readme.1st

NO_CDROM=	Copy of CD must be sent to author

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

WRKSRC=		${WRKDIR}/adom
NO_BUILD=	yes
STRIP=		# empty: do not strip linux binary!

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/adom ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in readme.1st adomfaq.txt manual.doc
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
