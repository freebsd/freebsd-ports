# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	tnote
PORTVERSION=	0.2.1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small note taking program for the terminal

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PLIST_FILES=	bin/tnote man/man1/tnote.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
