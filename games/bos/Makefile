# New ports collection makefile for:	bos
# Date created:				14 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	bos
PORTVERSION=	2.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.boswars.org/files/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A real-time strategy game

RUN_DEPENDS=	stratagus:${PORTSDIR}/games/stratagus

NO_WRKSUBDIR=	yes

do-build:
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} 'exec stratagus -d ${DATADIR} "$$@"') \
	  > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	cd ${WRKSRC}/data.bos && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
