# New ports collection makefile for:	py-mutagen
# Date created:			15 May 2006
# Whom:				Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$

PORTNAME=	mutagen
PORTVERSION=	1.12
CATEGORIES=	audio python
MASTER_SITES=	http://www.sacredchao.net/~piman/software/ \
		http://www.tortall.net/mirrors/piman-software/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	A Python-based audio metadata tag reader and writer

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

MAN1=		mutagen-inspect.1 mutagen-pony.1 mid3v2.1 moggsplit.1 \
		mid3iconv.1

post-patch:
	${REINPLACE_CMD} -e "s,share/man/man1,man/man1,g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
