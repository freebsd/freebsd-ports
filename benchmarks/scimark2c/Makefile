# New ports collection makefile for:	scimark2c
# Date created:		Sat Apr 05 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	scimark2c
PORTVERSION=	2.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://math.nist.gov/scimark2/
DISTNAME=	${PORTNAME}

MAINTAINER=	thierry@pompo.net
COMMENT=	An ANSI C version of the SciMark2 benchmark

PLIST_FILES=	bin/scimark2
WRKSRC=		${WRKDIR}
USE_ZIP=	yes

MALLOC2STD=	kernel.c Stopwatch.c Random.c array.c

post-patch:
.for file in ${MALLOC2STD}
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|" ${WRKSRC}/${file}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scimark2 ${PREFIX}/bin

post-install:
	@${ECHO} "*****************************************************************************"
	@${ECHO} ""
	@${ECHO} " Just run scimark2 or scimark2 -large"
	@${ECHO} ""
	@${ECHO} " The first SciMark number reported is the composite score, followed by the an"
	@${ECHO} " approximate Mflop rate for each kernel."
	@${ECHO} ""
	@${ECHO} " You may try to hack CC or CFLAGS in /etc/make.conf..."
	@${ECHO} ""
	@${ECHO} "*****************************************************************************"

.include <bsd.port.mk>
