# New ports collection makefile for:   Atari800-0.8.0
# Version required:	0.8.1
# Date created:		29th April, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $Id: Makefile,v 1.1.1.1 1997/10/29 09:07:08 tg Exp $
#

DISTNAME=	Atari800-0.8.1
PKGNAME=	atari800-0.8.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.signus.demon.co.uk/david/atari/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_FILES}

MAINTAINER=	sutton@aardvark.apana.org.au

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	xview:${PORTSDIR}/x11-toolkits/xview-lib

RESTRICTED=	"xf25 contains copyright ROMs and cannot be distributed"
NO_PACKAGE=	${RESTRICTED}

EXTRA_FILES=	xf25.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# Source building
#
ALL_TARGET=	freebsd-xview

# Installation
#
# Install and mkdir needed for 2.1.5R standard bsd.port.mk file. Other
# variables are needed for the post-install target.
#
ATARI_DOC=	${PREFIX}/share/doc/atari
ATARI_ROM=	ataribas.rom atariosb.rom atarixl.rom
ATARI_LIB=	${PREFIX}/lib/atari
SED_CONFIG=	${ATARI_LIB:S/\//\\\//g}\/
DOC_FILES= 	BUGS CHANGES COPYING CREDITS INSTALL README TODO USAGE
MAN1=		atari800.1

# Unpack roms from xf25.zip Atari Emulator for DOS and process the
# configuration file to include the right paths for the rom files.
#
post-extract:
	@${ECHO_MSG} "===>  Unzipping ROM files"
	unzip -Lo ${DISTDIR}/${DIST_SUBDIR}/${EXTRA_FILES} ${ATARI_ROM} -d ${WRKSRC}/

	@${ECHO_MSG} "===>  Processing configuration file"
	${SED} "s/GUMBY/${SED_CONFIG}/g" < ${FILESDIR}/atari800.cfg \
		> ${WRKSRC}/atari800.cfg

	@${ECHO_MSG} "===>  Copying config.h to work directory"
	${CP} ${FILESDIR}/config.h ${WRKSRC}/

# Install roms, extra docs and config file.
#
post-install:
	@${ECHO_MSG} "===>  Installing ROM files"
	-${MKDIR} ${ATARI_LIB}
	for file in ${ATARI_ROM} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${ATARI_LIB}/ ;\
	done

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing distribution document files"
	-${MKDIR} ${ATARI_DOC}
	for file in ${DOC_FILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${ATARI_DOC}/ ;\
	done
	${INSTALL_DATA} ${PKGDIR}/DESCR ${ATARI_DOC}/README.FreeBSD
.endif

	@${ECHO_MSG} "===>  Installing configuration file"
	${INSTALL} -c -o root -g wheel -m 664 ${WRKSRC}/atari800.cfg \
		${ATARI_LIB}/

.include <bsd.port.mk>
