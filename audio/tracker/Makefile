# New ports collection makefile for:	tracker
# Date created:		2 Oct 1994
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	tracker
PORTVERSION=	5.3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.uni-trier.de/pub/unix/audio/tracker/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

RESTRICTED=	"Non-redistributable beta"

WRKSRC=		${WRKDIR}/tracker
INSTALL_TARGET=	install install.info

post-install:
	@install-info ${PREFIX}/info/tracker.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tracker
.for file in FAQ readme tracker.doc
	${INSTALL_DATA} ${WRKSRC}/Docs/${file} ${PREFIX}/share/doc/tracker
.endfor
	@${MKDIR} ${PREFIX}/share/doc/tracker/html
	${INSTALL_DATA} ${WRKSRC}/Docs/Html/* ${PREFIX}/share/doc/tracker/html
.endif

.include <bsd.port.mk>
