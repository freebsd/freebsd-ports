# New ports collection makefile for:	frotz
# Date created:				16 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	frotz
PORTVERSION=	2.43
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/frotz/ \
		http://wuarchive.wustl.edu/doc/misc/if-archive/infocom/interpreters/frotz/ \
		http://www.ifarchive.org/if-archive/infocom/interpreters/frotz/

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	Infocom games interpreter

MAKE_ARGS=	CC="${CC}" OPTS="${CFLAGS}" PREFIX="${PREFIX}" \
		CONFIG_DIR="${PREFIX}/etc" INCL="" LIB=""

MAN6=		frotz.6

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/frotz.6 ${MANPREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS HOW_TO_PLAY README
	@${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
