# ex:ts=8
# Ports collection makefile for:  bochs
# Version required: 0.0
# Date created:			  16 December 1997
# Whom:				  alex
#
# $FreeBSD$
#

DISTNAME=	bochs-${DATE}c
CATEGORIES= 	emulators
MASTER_SITES= 	ftp://ftp.bochs.com/pub/

MAINTAINER=	obrien@FreeBSD.org

VGABIOS=	VGABIOS-elpin-2.20
BIOS=		BIOS-bochs-990925a
DATE= 		2000_0104

USE_XLIB=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-cpu-level=4 --enable-vga \
		--with-x11 --prefix=${PREFIX}

.ifdef(WANT_DEBUGGER)
CONFIGURE_ARGS+= --enable-debugger --enable-disasm
.endif

RESTRICTED=	"Commercial software"
NO_CDROM=	${RESTRICTED}

pre-configure:
	@${PERL} -pi.fbsd \
		 -e 's|^vgaromimage:\sbios/|vgaromimage: ${PREFIX}/lib/bochs/bios/| ;' \
		 -e 's|^romimage:\sfile=bios/|romimage: file=${PREFIX}/lib/bochs/bios/|' \
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
