# New ports collection makefile for:    adom
# Date created:		22 July 1999
# Whom:			Oleg V. Volkov <rover@lglobus.ru>
#
# $FreeBSD$
#

PORTNAME=	adom
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://www.adom.de/adom/download/linux/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-elf

MAINTAINER=	sr-13@mail.ru
COMMENT=	An rogue-like advanced rpg with color support (binary port)

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

NO_CDROM=	Copy of CD must be sent to author

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
WRKSRC=		${WRKDIR}/adom
NO_BUILD=	yes
STRIP=		# empty: do not strip linux binary!

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/adom ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in readme.1st adomfaq.txt manual.doc
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
