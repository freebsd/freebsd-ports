# New ports collection makefile for:	meQCC
# Date created:				16 Jan 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	meqcc
PORTVERSION=	1.4
CATEGORIES=	games devel
MASTER_SITES=	http://wiki.quakesrc.org/files/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	MrElusive's QuakeC compiler

USE_GMAKE=	yes
USE_ZIP=	yes

MAKEFILE=	${WRKSRC}/linux.mak

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|h|mak|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@${REINPLACE_CMD} -e 's/<io\.h>/<unistd\.h>/' ${WRKSRC}/cmdlib.c \
		${WRKSRC}/qcc.c ${WRKSRC}/l_log.c
	@${REINPLACE_CMD} -e '/<conio\.h>/d' ${WRKSRC}/l_log.c
	@${REINPLACE_CMD} -e 's/unsigned long t/time_t t/' ${WRKSRC}/l_precomp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcc ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/[^g]*.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake-source/Makefile.include"

.include <bsd.port.mk>
