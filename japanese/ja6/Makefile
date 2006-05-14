# New ports collection makefile for:	ja6
# Date created:		2006-04-10
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	ja6
PORTVERSION=	2003.03.09.l
CATEGORIES=	japanese
MASTER_SITES=	http://members.tripod.com/~so_o2/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/
DISTVERSIONSUFFIX=	-bin

MAINTAINER=	nivit@email.it
COMMENT=	A Japanese Symbols Trainer

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	yes

do-install:
	@${INSTALL} -d ${DATADIR}
	${CP} -Rp ${WRKSRC}/ ${DATADIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/
	@${CHMOD} -R a+rx,go-w ${DATADIR}/
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/${PORTNAME}-run
	@${ECHO_CMD} 'exec ${DATADIR}/ja6 -p ${DATADIR} "$$@"' >> ${WRKDIR}/${PORTNAME}-run
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-run ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
