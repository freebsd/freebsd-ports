# New ports collection makefile for:   Atari800
# Date created:		29th April, 1997
# Whom:			Joel Sutton <jsutton@webnet.com.au>
#
# $FreeBSD$
#

PORTNAME=	atari800
PORTVERSION=	1.2.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xf25.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	"xf25 contains copyright ROMs and cannot be distributed."
NO_PACKAGE=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=x11

MAN1=		atari800.1

ATARI_XF=	ataribas.rom atariosb.rom atarixl.rom demos1.xfd \
		demos2.xfd dos25.xfd mydos45d.atr

post-extract:
	@unzip -q -L -o ${DISTDIR}/${DIST_SUBDIR}/xf25.zip ${ATARI_XF} -d ${WRKSRC}

post-patch:
	@${CP} ${FILESDIR}/atari800.cfg ${WRKSRC}
	@${PERL} -pi -e 's|GUMBY|${DATADIR}|g' ${WRKSRC}/atari800.cfg
	@${PERL} -pi -e 's|/etc|${DATADIR}|g' ${WRKSRC}/rt-config.c
	@${PERL} -pi -e 's|tmpnam|mkstemp|g' ${WRKSRC}/devices.c \
		${WRKSRC}/compfile.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/atari800 ${PREFIX}/bin/atari800
	@${INSTALL_MAN} ${WRKSRC}/atari800.man ${MANPREFIX}/man/man1/atari800.1
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} -m 644 ${WRKSRC}/atari800.cfg ${DATADIR}
.for file in ${ATARI_XF}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES CREDITS FAQ INSTALL README TODO USAGE
	@${INSTALL_DATA} ${WRKSRC}/../DOC/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
