# New ports collection makefile for:   Atari800
# Date created:		29th April, 1997
# Whom:			Joel Sutton <jsutton@webnet.com.au>
#
# $FreeBSD$
#

PORTNAME=	atari800
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.signus.demon.co.uk/Software/Portable/Atari800e/ \
		http://cas3.zlin.vutbr.cz/~stehlik/a800/
DISTNAME=	Atari800-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_FILES}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

DIST_SUBDIR=	atari
EXTRA_FILES=	xf25.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

ALL_TARGET=	freebsd-x11

RESTRICTED=	"xf25 contains copyright ROMs and cannot be distributed."
NO_PACKAGE=	${RESTRICTED}

ATARI_DOC=	${PREFIX}/share/doc/atari
ATARI_XF=	ataribas.rom atariosb.rom atarixl.rom demos1.xfd \
		demos2.xfd dos25.xfd mydos45d.atr
ATARI_LIB=	${PREFIX}/share/atari
SED_CONFIG=	${ATARI_LIB:S/\//\\\//g}
DOC_FILES=	BUGS CHANGES CREDITS INSTALL README TODO USAGE

MAN1=		atari800.1

post-extract:
	@${ECHO_MSG} "===>  Unzipping ROM files"
	unzip -q -L -o ${_DISTDIR}/${EXTRA_FILES} ${ATARI_XF} -d ${WRKSRC}
	@${ECHO_MSG} "===>  Processing configuration file"
	${SED} "s/GUMBY/${SED_CONFIG}/g" < ${FILESDIR}/atari800.cfg \
		> ${WRKSRC}/atari800.cfg

	@${ECHO_MSG} "===>  Copying config.h to work directory"
	${CP} ${FILESDIR}/config.h ${WRKSRC}

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
.for file in ${ATARI_XF}
	${INSTALL_DATA} ${WRKSRC}/${file} ${ATARI_LIB}
.endfor

	@${ECHO_MSG} "===>  Installing configuration file"
	${INSTALL_DATA} -m 664 ${WRKSRC}/atari800.cfg ${ATARI_LIB}

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing distribution document files"
	-${MKDIR} ${ATARI_DOC}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${ATARI_DOC}
.endfor
	${INSTALL_DATA} ${DESCR} ${ATARI_DOC}/README.FreeBSD
.endif

.include <bsd.port.mk>
