# New ports collection makefile for:	prodosemu
# Date created:		18th February 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	prodosemu
PORTVERSION=	0.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://apple2.caltech.edu/pub/apple2/emulators/
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A text based Apple IIe ProDOS emulator

NO_PACKAGE=	yes
RESTRICTED=	apple.rom copyright is owned by Apple and cannot be distributed.
WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/prodosemu
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/prodosemu
.endif

.include <bsd.port.mk>
