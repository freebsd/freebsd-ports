# New ports collection makefile for:   harbour
# Date created:        9 May 2003
# Whom:                David G. Holm <harbour@netfang.net>
#
# $FreeBSD$
#

PORTNAME=	harbour
PORTVERSION=	0.43.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.jsd0.com/public/harbour/dgh/

MAINTAINER=	harbour@netfang.net
COMMENT=	An open source Clipper-compatible compiler

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

# Not 64-bit clean
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}
USE_BISON=	yes
USE_FLEX=	yes
USE_GMAKE=	yes
NO_INSTALL_MANPAGES=yes

HB_DIR=		${WRKDIR}/${PORTNAME}

.if defined(NOPORTDOCS)
post-install:
	${INSTALL_PROGRAM} ${HB_DIR}/bin/harbour ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbdoc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbmake ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbpp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbrun ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbtest ${PREFIX}/bin
	${INSTALL_DATA} ${HB_DIR}/include/hb* ${PREFIX}/include
	${INSTALL_DATA} ${HB_DIR}/lib/*.a ${PREFIX}/lib
	.endif
	-@${ECHO}
	-@${ECHO} @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	-@${ECHO} @
	-@${ECHO} @ Executable files are installed in ${PREFIX}/bin.
	-@${ECHO} @
	-@${ECHO} @ Header files are installed in ${PREFIX}/include.
	-@${ECHO} @
	-@${ECHO} @ Library files are installed in ${PREFIX}/lib.
	-@${ECHO} @
	-@${ECHO} @ See pkg-plist for a list of all installed files.
	-@${ECHO} @
	-@${ECHO} @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	-@${ECHO}
.else
post-install:
	${INSTALL_PROGRAM} ${HB_DIR}/bin/harbour ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbdoc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbmake ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbpp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbrun ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbtest ${PREFIX}/bin
	${INSTALL_PROGRAM} ${HB_DIR}/bin/hbverfix ${PREFIX}/bin
	${INSTALL_DATA} ${HB_DIR}/include/hb* ${PREFIX}/include
	${INSTALL_DATA} ${HB_DIR}/lib/*.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/harbour
	${INSTALL_MAN} ${HB_DIR}/doc/*.txt ${PREFIX}/share/doc/harbour
	${MKDIR} ${PREFIX}/share/doc/harbour/en
	${INSTALL_MAN} ${HB_DIR}/doc/en/*.txt ${PREFIX}/share/doc/harbour/en
	${MKDIR} ${PREFIX}/share/doc/harbour/es
	${INSTALL_MAN} ${HB_DIR}/doc/es/*.txt ${PREFIX}/share/doc/harbour/es
	-@${ECHO}
	-@${ECHO} @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	-@${ECHO} @
	-@${ECHO} @ Executable files are installed in ${PREFIX}/bin.
	-@${ECHO} @
	-@${ECHO} @ Header files are installed in ${PREFIX}/include.
	-@${ECHO} @
	-@${ECHO} @ Library files are installed in ${PREFIX}/lib.
	-@${ECHO} @
	-@${ECHO} @ Documentation files are installed in ${PREFIX}/share/doc/harbour,
	-@${ECHO} @ ${PREFIX}/share/doc/harbour/en, and ${PREFIX}/share/doc/harbour/es.
	-@${ECHO} @
	-@${ECHO} @ See pkg-plist for a list of all installed files.
	-@${ECHO} @
	-@${ECHO} @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	-@${ECHO}
.endif

.include <bsd.port.mk>
