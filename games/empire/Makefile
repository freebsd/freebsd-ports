# New ports collection makefile for:	empire
# Date created:				13 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	empire
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/
DISTNAME=	vms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	Solitaire empire game "VMS Empire"

MAN6=		empire.6
PLIST_FILES=	bin/empire
PORTDOCS=	BUGS README
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} >= 700042
	@${REINPLACE_CMD} -e 's/static void/void/g' ${WRKSRC}/game.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin/empire
	${INSTALL_MAN} ${WRKSRC}/vms-empire.6 ${MANPREFIX}/man/man6/empire.6
.if !defined(NOPORTDOCS)
.for file in BUGS README
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
