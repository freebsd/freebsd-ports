# New ports collection makefile for:	ja-pycodec
# Date created:		29 April 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	1.4.11
CATEGORIES=	japanese python converters
MASTER_SITES=	http://www.python.jp/Zope/download/JapaneseCodecs/ \
		http://www.asahi-net.or.jp/~rd6t-kjym/python/JapaneseCodecs/dist/
DISTNAME=	JapaneseCodecs-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Unicode codecs for Japanese charsets

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
DOCSDIR=	${PREFIX}/share/doc/ja-pycodec

post-patch:
	${REINPLACE_CMD} -e 's,^static,static const,g' \
		${WRKSRC}/src/_japanese_codecs.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR}
.endif

.include <bsd.port.mk>
