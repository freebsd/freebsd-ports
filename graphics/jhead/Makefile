# New ports collection makefile for:   jhead
# Date created:                01 Dec 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	jhead
PORTVERSION=	2.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	xride@x12.dk
COMMENT=	Exif Jpeg camera setting parser, rotator and much more

RUN_DEPENDS=	jpegtran:${PORTSDIR}/graphics/jpeg

MAKEFILE=	makefile
MANCOMPRESSED=	yes

PORTDOCS=	usage.html
PLIST_FILES=	bin/jhead
MAN1=		jhead.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1.gz ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/usage.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
