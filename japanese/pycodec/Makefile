# New ports collection makefile for:	ja-pycodec
# Date created:		29 April 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	1.4.7
CATEGORIES=	japanese python converters
MASTER_SITES=	http://www.python.jp/Zope/download/JapaneseCodecs/
DISTNAME=	JapaneseCodecs-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
DOCSDIR=	${PREFIX}/share/doc/ja-pycodec

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR}
.endif

.include <bsd.port.mk>
