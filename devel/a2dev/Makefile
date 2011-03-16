# New ports collection makefile for:    a2dev
# Date created:         		1 July 1998
# Whom:                 		Archie L. Cobbs <archie@whistle.com>
#
# $FreeBSD$
#

PORTNAME=	a2dev
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	archie
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apple II 6502 assembler, linker, loader, and object file viewer

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GMAKE=	yes
MAN1=		a2asm.1 a2link.1 a2load.1 a2objx.1

PLIST_FILES=	bin/a2asm bin/a2link bin/a2load bin/a2objx

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=			Does not compile on !i386
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-O3|${CFLAGS}|' \
		${WRKSRC}/Make.defs

.include <bsd.port.post.mk>
