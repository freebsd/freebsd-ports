# New ports collection makefile for:	netdic
# Date created:		19 July 2002
# Whom:			Tae-seong Kim <rapzzard@rapzzard.pe.kr>>
#
# $FreeBSD$
#

PORTNAME=	netdic
PORTVERSION=	0.1
CATEGORIES=	korean deskutils
MASTER_SITES=	http://user.chollian.net/~tadboy/source/NetDic/
DISTNAME=	netdic
EXTRACT_SUFX=	.c

MAINTAINER=	rapzzard@rapzzard.pe.kr

do-extract:
	@${RM} -rf ${WRKDIR} && \
	${MKDIR} ${WRKDIR} && \
	cd ${WRKDIR} && \
	${CP} ${DISTDIR}/${DISTFILES} .

do-build:
	${CC} -o ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}.c

do-install:
	${CP} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
