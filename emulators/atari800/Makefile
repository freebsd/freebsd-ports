# New ports collection makefile for:   Atari800
# Date created:		29th April, 1997
# Whom:			Joel Sutton <jsutton@webnet.com.au>
#
# $FreeBSD$
#

PORTNAME=	atari800
PORTVERSION=	1.0.7
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.sophics.cz/pub/Atari800/src/ \
		http://joy.sophics.cz/www/
DISTFILES=	a800s${PORTVERSION:S/.//g}.zip xf25.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	a800s${PORTVERSION:S/.//g}.zip

MAINTAINER=	ports@FreeBSD.org

RESTRICTED=	"xf25 contains copyright ROMs and cannot be distributed."
NO_PACKAGE=	${RESTRICTED}

WRKSRC=		${WRKDIR}/Atari800-${PORTVERSION}/src
USE_ZIP=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

.if defined(WITH_SHM)
ALL_TARGET=	x11-shm
.else
ALL_TARGET=	x11
.endif

MAN1=		atari800.1

ATARI_LIB=	${PREFIX}/share/${PKGBASE}
ATARI_XF=	ataribas.rom atariosb.rom atarixl.rom demos1.xfd \
		demos2.xfd dos25.xfd mydos45d.atr
ATARI_DOC=	${PREFIX}/share/doc/${PKGBASE}
DOC_FILES=	BUGS CHANGES CREDITS FAQ INSTALL README TODO USAGE

post-extract:
	@unzip -q -L -o ${_DISTDIR}/xf25.zip ${ATARI_XF} -d ${WRKSRC}

post-patch:
	@${LN} -sf Makefile.unix ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/config.h ${WRKSRC}
	@${TOUCH} ${WRKSRC}/.atari800
	@${SED} -e 's:GUMBY:${ATARI_LIB}:g' \
		${FILESDIR}/atari800.cfg > ${WRKSRC}/atari800.cfg

post-install:
	@${MKDIR} ${ATARI_LIB}
	${INSTALL_DATA} -m 664 ${WRKSRC}/atari800.cfg ${ATARI_LIB}
.for file in ${ATARI_XF}
	${INSTALL_DATA} ${WRKSRC}/${file} ${ATARI_LIB}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${ATARI_DOC}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/../DOC/${file} ${ATARI_DOC}
.endfor
	${INSTALL_DATA} ${DESCR} ${ATARI_DOC}/README.FreeBSD
.endif

.include <bsd.port.mk>
