# ex:ts=8
# New ports collection makefile for:   bochs
# Version required:    990219a
# Date created:        16 December 1997
# Whom:                alex
#
# $FreeBSD$
#

VGABIOS=	VGABIOS-elpin-2.20
BIOS=		BIOS-bochs-990925a
DATE= 		991114

DISTNAME=	bochs-${DATE}a
CATEGORIES= 	emulators
MASTER_SITES= 	ftp://ftp.bochs.com/pub/

MAINTAINER=	obrien@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-cpu-level=4 --enable-vga \
		--with-x11 --prefix=${PREFIX}

WRKSRC=		${WRKDIR}/bochs-${DATE}a

RESTRICTED=	"Commercial software"
NO_CDROM=	${RESTRICTED}

pre-configure:
	@${PERL} -pi.fbsd \
		-e 's|^vgaromimage:\sbios/|vgaromimage: ${PREFIX}/bios/| ;' \
		-e 's|^romimage:\sfile=bios/|romimage: file=${PREFIX}/bios/|' \
		${WRKSRC}/.bochsrc

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
