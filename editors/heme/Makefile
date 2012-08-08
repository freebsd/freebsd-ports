# New ports collection makefile for:	heme
# Date created:				29 May 2012
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	heme
PORTVERSION=	0.4.2
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast console hex editor for Unix-like systems

LICENSE=	GPLv2

ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CFLAGS="${CFLAGS} -Wall -DHAVE_MMAP" INSTALL_PREFIX="${PREFIX}"

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
