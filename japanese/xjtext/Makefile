# New ports collection makefile for:	xjtext
# Date created:		8 July 2000
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	xjtext
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://plaza.harmonix.ne.jp/~onizuka/
DISTNAME=	XJTEXT-${PORTVERSION}

MAINTAINER=	sada@FreeBSD.org

USE_BISON=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
EXAMPLEDIR=	${PREFIX}/share/examples/xjtext
DOCDIR=		${PREFIX}/share/doc/xjtext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjtext ${PREFIX}/bin

post-install:
	strip ${PREFIX}/bin/xjtext
	${MKDIR} ${EXAMPLEDIR}
.for i in FSS README YAMA \
		Ao.png Back2.png Brown.png Royal.png Royal2.png
	${INSTALL_DATA} ${WRKSRC}/$i ${EXAMPLEDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${DOCDIR}
.endif

.include <bsd.port.mk>
