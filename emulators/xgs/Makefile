# New ports collection makefile for:	xgs
# Date created:		2nd May, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#
# This is the stable release of the xgs emulator. Sound support is
# currently broken.

PORTNAME=	xgs
PORTVERSION=	0.50
CATEGORIES=	emulators
MASTER_SITES=	http://www.inwards.com/xgs/ \
		ftp://ftp.apple.asimov.net/pub/apple_II/emulators/rom_images/
DISTFILES=	xgs050.tgz xgs.rom

MAINTAINER=	ports@FreeBSD.org

DIST_SUBDIR=	xgs
EXTRACT_ONLY=	xgs050.tgz
RESTRICTED=	"xgs.rom copyright is owned by Apple and cannot be distributed"
NO_PACKAGE=	${RESTRICTED}

# Source building
#
WRKSRC=		${WRKDIR}/xgs
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x --datadir='${PREFIX}/libdata'

# Directories etc...
#
XGS_DOC=	${PREFIX}/share/doc/xgs
XGS_LIB=	${PREFIX}/libdata/xgs
DOC_FILES= 	CHANGES.TXT COMPAT.TXT INSTALL.TXT TODO.TXT \
		IWM-DOC.TXT XGS-FAQ.TXT

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/xgs.rom ${XGS_LIB}
	${INSTALL_DATA} -m 666 /dev/null ${XGS_LIB}/xgs.ram
.if !defined(NOPORTDOCS)
	@${MKDIR} ${XGS_DOC}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${XGS_DOC}
.endfor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${XGS_DOC}
.endif

.include <bsd.port.mk>
