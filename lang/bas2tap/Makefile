# New ports collection makefile for:	bas2tap
# Date created:			2007-06-26
# Whom:				Rene Ladan <r.c.ladan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bas2tap
PORTVERSION=	2.5
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.worldofspectrum.org/pub/sinclair/tools/generic/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//}-generic

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Convert 48k/128k ZX Spectrum BASIC text files to TAP files

LICENSE=	GPLv2

USE_ZIP=	yes

NO_WRKSUBDIR=	yes
PORTDOCS=	${PORTNAME}.doc
PLIST_FILES=	bin/${PORTNAME}

do-build:
	${CC} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME} -lm ${CFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
