# New ports collection makefile for:    adom
# Date created:		22 July 1999
# Whom:			Oleg V. Volkov <rover@lglobus.ru>
#
# $FreeBSD$
#

PORTNAME=	adom
PORTVERSION=	1.0.0
CATEGORIES=	games linux
MASTER_SITES=	http://www.adom.de/adom/download/linux/
DISTNAME=	adom-100-elf

MAINTAINER=	rover@lglobus.ru

RUN_DEPENDS=	${LINUXBASE}/lib/libc-2.2.2.so:${PORTSDIR}/emulators/linux_base-7

WRKSRC=		${WRKDIR}/adom

ONLY_FOR_ARCHS=	i386
NO_CDROM=	Copy of CD must be sent to author
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
