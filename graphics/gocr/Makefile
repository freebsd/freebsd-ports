# New ports collection makefile for:	gocr
# Date created:				03 June 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	gocr
PORTVERSION=	0.38
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jocr

MAINTAINER=	kay_lehmann@web.de
COMMENT=	GOCR/JOCR is an OCR (Optical Character Recognition) program

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		gocr.1

PORTDOCS=	examples.txt gocr.html unicode.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
