# Created by: Byung-Hee HWANG <bh@izb.knu.ac.kr>
# $FreeBSD$

PORTNAME=	mutagen
PORTVERSION=	1.35.1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python-based audio metadata tag reader and writer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USES?=		python:2.7+ shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	tools/mid3cp tools/mid3iconv tools/mid3v2 \
		tools/moggsplit tools/mutagen-inspect tools/mutagen-pony

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
