# New ports collection makefile for:   xgs-0.50
# Version required:	0.50
# Date created:		2nd May, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
# FreeBSD Version:	2.1.5-RELEASE
#
# $FreeBSD$
#

# This is the stable release of the xgs emulator. Sound support is
# currently broken.

# Distfile collection and extraction stuff
#      
DISTNAME=	xgs-0.50-src
PKGNAME=	xgs-0.50
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.optera.com/pub/xgs/ \
		ftp://ftp.apple.asimov.net/pub/apple_II/emulators/rom_images/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xgs.rom

BROKEN='fetch'

MAINTAINER=	sutton@aardvark.apana.org.au

DIST_SUBDIR=	xgs
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
RESTRICTED=	"xgs.rom copyright is owned by Apple and cannot be distributed"
NO_PACKAGE=	${RESTRICTED}

# Source building
#
WRKSRC=		${WRKDIR}/xgs
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x --datadir="${PREFIX}/lib"

# Directories etc...
#
XGS_DOC=	${PREFIX}/share/doc/xgs
XGS_LIB=	${PREFIX}/lib/xgs
DOC_FILES= 	CHANGES.TXT COMPAT.TXT INSTALL.TXT TODO.TXT \
		IWM-DOC.TXT XGS-FAQ.TXT

post-install:
.if !defined(NOPORTDOCS)
	-${MKDIR} ${XGS_DOC}
	for file in ${DOC_FILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$file ${XGS_DOC}/ ;\
	done
	${INSTALL_DATA} ${PKGDIR}/DESCR ${XGS_DOC}/README.FreeBSD
.endif
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/xgs.rom ${XGS_LIB}/
	${INSTALL_DATA} -m 666 /dev/null ${XGS_LIB}/xgs.ram

.include <bsd.port.mk>
