# New ports collection makefile for:	kdrill
# Date created:		14 November 2000
# Whom:			Seth Kingsley <sethk@osd.bsdi.com>
#
# $FreeBSD$
#

PORTNAME=	kdrill
PORTVERSION=	6.4
CATEGORIES=	japanese
MASTER_SITES=	http://www.bolthole.com/kdrill/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	sethk@meowfishies.com
COMMENT=	A program to quiz you on the meanings of Kanji

# Explictly state HTML'ized man pages in packing list since not all are
# generated from imake.
XFREE86_HTML_MAN=no
MAN1=		kdrill.1 makedic.1 makeedict.1

MANCOMPRESSED=	yes
USE_IMAKE=	yes
MAKE_ENV+=	LOCALBASE=${LOCALBASE}

RUN_DEPENDS+=	xjdic:${PORTSDIR}/japanese/edict

post-build:
	@cd ${WRKSRC}/makedic && ${MAKE} ${MAKE_ENV} clean all

DATADIR=	${PREFIX}/share/dict/kdrill
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makedic/makedic ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/makedic/makeedict ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/makedic/makedic.1 \
	    ${PREFIX}/man/man1
	${GZIP_CMD} ${PREFIX}/man/man1/makedic.1
	${INSTALL_MAN} ${WRKSRC}/makedic/makeedict.1 \
	    ${PREFIX}/man/man1
	${GZIP_CMD} ${PREFIX}/man/man1/makeedict.1
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/makedic/fullkatahira.edic ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/makedic/hira.edic ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/makedic/hiraplus.edic ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/makedic/kata.edic ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/makedic/kataplus.edic ${DATADIR}

.include <bsd.port.mk>
