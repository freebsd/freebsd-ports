# New ports collection makefile for:	le
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	le
PORTVERSION=	1.13.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.yars.free.net/pub/source/le/ \
		ftp://ftp.yar.ru/pub/source/le/

MAINTAINER=	az@FreeBSD.org
COMMENT=	Text editor

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		le.1
PORTDOCS=	FEATURES HISTORY NEWS README TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
