# New ports collection makefile for:	meQCC
# Date created:				16 Jan 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	meqcc
PORTVERSION=	1.4
CATEGORIES=	games devel
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	MrElusive's QuakeC compiler

LICENSE=	GPLv2

USE_ZIP=	yes
USE_DOS2UNIX=	yes
MAKEFILE=	linux.mak

PLIST_FILES=	bin/meqcc
PORTDOCS=	*

post-extract:
	@${REINPLACE_CMD} -e 's/<io\.h>/<unistd.h>/ ; /<conio\.h>/d' \
		${WRKSRC}/l_log.c
	@${REINPLACE_CMD} -e 's/unsigned long t/time_t t/' \
		${WRKSRC}/l_precomp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcc ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/[^gr]*.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake-source/Makefile.include"
.include <bsd.port.mk>
