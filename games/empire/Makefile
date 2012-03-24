# New ports collection makefile for:	empire
# Date created:				13 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	empire
PORTVERSION=	1.9
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/
DISTNAME=	vms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solitaire empire game "VMS Empire"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_SAFE=	yes

MAN6=		empire.6
PORTDOCS=	BUGS README
PLIST_FILES=	bin/empire

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS/#CFLAGS/ ; \
		 s/-lncurses/-lcurses/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/static void/void/g' ${WRKSRC}/game.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin/empire
	${INSTALL_MAN} ${WRKSRC}/empire.6 ${MAN6PREFIX}/man/man6/empire.6
.if !defined(NOPORTDOCS)
.for file in ${PORTDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
