# New ports collection makefile for:   Atari800-0.8.6
# Version required:	0.8.6
# Date created:		29th April, 1997
# Whom:			Joel Sutton <jsutton@webnet.com.au>
#
# $FreeBSD$
#

DISTNAME=	Atari800-0.8.6
PKGNAME=	atari800-0.8.6
CATEGORIES=	emulators
MASTER_SITES=	http://www.signus.demon.co.uk/Software/Portable/Atari800e/ \
		http://cas3.zlin.vutbr.cz/~stehlik/a800/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_FILES}

MAINTAINER=	jsutton@webnet.com.au

BROKEN='MD5 checksum mismatch.  Also xf25.zip has an "End-of-central-directory signature not found" when unzipping problem.'

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
.if defined(ATARI) && (${ATARI} == "freebsd-xview")
LIB_DEPENDS=	xview:${PORTSDIR}/x11-toolkits/xview
.endif
DIST_SUBDIR=	atari
EXTRA_FILES=	xf25.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

ALL_TARGET=	${ATARI}

RESTRICTED=	"xf25 contains copyright ROMs and cannot be distributed."
NO_PACKAGE=	${RESTRICTED}

ATARI_DOC=	${PREFIX}/share/doc/atari
ATARI_XF=	ataribas.rom atariosb.rom atarixl.rom demos1.xfd \
		demos2.xfd dos25.xfd mydos45d.atr
ATARI_LIB=	${PREFIX}/lib/atari
SED_CONFIG=	${ATARI_LIB:S/\//\\\//g}
DOC_FILES= 	BUGS CHANGES COPYING CREDITS INSTALL README TODO USAGE

MAN1=		atari800.1

.if !defined(ATARI)
pre-extract:
	@${ECHO_MSG} "Please define the environment variable ATARI to"
	@${ECHO_MSG} "determine how to build the emulator. Your choices are:"
	@${ECHO_MSG} "   freebsd-ncurses, freebsd-x11, freebsd-xview. "
	@${ECHO_MSG}
	@${FALSE}
.endif
post-extract:
	@${ECHO_MSG} "===>  Unzipping ROM files"
	unzip -Lo ${DISTDIR}/${DIST_SUBDIR}/${EXTRA_FILES} ${ATARI_XF}\
		-d ${WRKSRC}/
	@${ECHO_MSG} "===>  Processing configuration file"
	${SED} "s/GUMBY/${SED_CONFIG}/g" < ${FILESDIR}/atari800.cfg \
		> ${WRKSRC}/atari800.cfg

	@${ECHO_MSG} "===>  Copying config.h to work directory"
	${CP} ${FILESDIR}/config.h ${WRKSRC}/

	@${ECHO_MSG} "===>  Copying UNIX makefile"
	${CP} ${WRKSRC}/Makefile.unix ${WRKSRC}/Makefile

post-patch:
	@${ECHO_MSG} "===>  Processing another configuration file"
	${CP} ${WRKSRC}/rt-config.c ${WRKSRC}/rt-config.c.temp
	${SED} "s/GUMBY/${SED_CONFIG}/g" <${WRKSRC}/rt-config.c.temp \
		> ${WRKSRC}/rt-config.c

# Install roms, extra docs and config file.
#
post-install:
	@${ECHO_MSG} "===>  Installing files from xf25.zip"
	-${MKDIR} ${ATARI_LIB}
	for file in ${ATARI_XF} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${ATARI_LIB}/ ;\
	done

	@${ECHO_MSG} "===>  Installing configuration file"
	${INSTALL} -c -o root -g wheel -m 664 ${WRKSRC}/atari800.cfg \
		${ATARI_LIB}/

.if (!defined(NOPORTDOCS))
	@${ECHO_MSG} "===>  Installing distribution document files"
	-${MKDIR} ${ATARI_DOC}
	for file in ${DOC_FILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${ATARI_DOC}/ ;\
	done
	${INSTALL_DATA} ${PKGDIR}/DESCR ${ATARI_DOC}/README.FreeBSD
.endif

.include <bsd.port.mk>
