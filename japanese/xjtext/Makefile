# New ports collection makefile for:	xjtext
# Date created:		8 July 2000
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	xjtext
PORTVERSION=	1.3
CATEGORIES=	japanese
MASTER_SITES=	http://plaza.harmonix.ne.jp/~onizuka/
DISTNAME=	XJTEXT-${PORTVERSION}

MAINTAINER=	sada@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		Imlib.5:${PORTSDIR}/graphics/imlib
BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

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
