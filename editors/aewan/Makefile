# New ports collection makefile for:	aewan
# Date created:				07.05.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	aewan
PORTVERSION=	1.0.01
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based program for the creation and editing of ASCII art

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		aecat.1 aewan.1 aemakeflic.1
MAN5=		aewan.5
PLIST_FILES=	bin/aecat bin/aewan bin/aemakeflic

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|OSTYPE == |OSTYPE = |g' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
