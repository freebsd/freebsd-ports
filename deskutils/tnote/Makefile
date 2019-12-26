# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	tnote
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small note taking program for the terminal

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv3

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils

SHEBANG_FILES=	tnote

PLIST_FILES=	bin/tnote man/man1/tnote.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${REINPLACE_CMD} -e 's|share/man|man|; \
		s|share/doc/tnote|${DOCSDIR_REL}|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
