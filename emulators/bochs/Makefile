# New ports collection makefile for:   bochs
# Version required:    990219a
# Date created:        16 December 1997
# Whom:                alex
#
# $FreeBSD$
#

VGABIOS=	VGABIOS-elpin-2.20
BIOS=		BIOS-bochs-990623a
DATE= 		990708

DISTNAME=	bochs-${DATE}a
CATEGORIES= 	emulators
MASTER_SITES= 	ftp://ftp.bochs.com/pub/

MAINTAINER=	ports@FreeBSD.ORG

USE_XLIB=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-cpu-level=4 --enable-vga \
		--with-x11 --prefix=${PREFIX}

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
	${INSTALL_MAN} ${WRKSRC}/docs-html/*.gif ${PREFIX}/share/doc/bochs
.endif

.include <bsd.port.mk>
