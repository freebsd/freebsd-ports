# New ports collection makefile for:   bochs
# Version required:    980124c
# Date created:        16 December 1997
# Whom:                alex
#
# $Id: Makefile,v 1.4 1998/01/19 04:00:30 alex Exp $
#

VGABIOS=	VGABIOS-elpin-2.00A
BIOS=		BIOS-bochs-980124a
DATE= 		980124

DISTNAME=	bochs-${DATE}c
CATEGORIES= 	emulators
MASTER_SITES= 	ftp://ftp.std.com/pub/bochs/

MAINTAINER=	alex@FreeBSD.ORG

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-80386 --enable-debugger --enable-memory=16 \
	--enable-v8086-mode --enable-paging --enable-vga \
	--enable-bochs-bios-hooks --enable-dma-floppy-io \
	--enable-processor-ips=200000

WRKSRC=		${WRKDIR}/bochs-${DATE}

RESTRICTED=	"Commercial software"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bochs ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/lib/bochs
	${INSTALL_DATA} ${WRKSRC}/.bochsrc ${PREFIX}/lib/bochs/bochsrc.sample
	-@${MKDIR} ${PREFIX}/lib/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/${VGABIOS} \
		${PREFIX}/lib/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/${BIOS} \
		${PREFIX}/lib/bochs/bios
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${PREFIX}/share/doc/bochs
	${INSTALL_MAN} ${WRKSRC}/docs-html/LICENSE ${PREFIX}/share/doc/bochs
	${INSTALL_MAN} ${WRKSRC}/docs-html/*.html ${PREFIX}/share/doc/bochs
.endif

.include <bsd.port.mk>
