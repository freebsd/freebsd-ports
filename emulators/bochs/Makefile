# New ports collection makefile for:   bochs
# Version required:    980513a
# Date created:        16 December 1997
# Whom:                alex
#
# $Id: Makefile,v 1.13 1998/12/01 08:04:23 asami Exp $
#

VGABIOS=	VGABIOS-elpin-2.20
BIOS=		BIOS-bochs-980717a
DATE= 		981102

DISTNAME=	bochs-${DATE}b
CATEGORIES= 	emulators
MASTER_SITES= 	ftp://ftp.bochs.com/pub/

MAINTAINER=	ports@FreeBSD.ORG

USE_XLIB=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-80386 --enable-memory=16 \
	--enable-v8086-mode --enable-paging --enable-vga \
	--enable-bochs-bios-hooks --enable-dma-floppy-io \
	--enable-processor-ips=200000

WRKSRC=		${WRKDIR}/bochs-${DATE}

RESTRICTED=	"Commercial software"
NO_CDROM=	${RESTRICTED}

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
