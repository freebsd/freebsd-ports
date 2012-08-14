# New ports collection makefile for:	tnote
# Date created:		2010-07-25
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	tnote
PORTVERSION=	0.2.1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small note taking program for the terminal

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		tnote.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/tnote

PORTDOCS=	*

post-extract:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e 's|(.share/doc[^)]*),||' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
