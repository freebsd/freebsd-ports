# New ports collection makefile for:	pylafax
# Date created:		6 January 2005
# Whom:			Michael Reifenberger (mike@Reifenberger.com)
#
# $FreeBSD$
#

PORTNAME=	pyla
PORTVERSION=	1.1.4
CATEGORIES=	comms python
MASTER_SITES=	http://www.teamsw.it/pyla/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyla${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mike@Reifenberger.com
COMMENT=	Hylafax client written in Python

#LIB_DEPENDS=	lirc_client.0:${PORTSDIR}/comms/lirc

WRKSRC=		${WRKDIR}/${PORTNAME}
DATADIR=	${PREFIX}/lib/pyla

USE_PYTHON=	yes
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

do-build:
	@(cd ${FILESDIR} && ${CP} pyla.sh ${WRKDIR})
	@(cd ${WRKDIR} && ${REINPLACE_CMD} \
		-e "s|%%PREFIX%%|${PREFIX}|g;" \
		-e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|g;" \
		pyla.sh)
	@(cd ${WRKSRC} && ${CP} language.en language.db)

pre-install:
	@${ECHO_CMD} '@exec ${MKDIR} %D/lib/pyla' > ${PLIST}
	@${ECHO_CMD} 'bin/pyla' >> ${PLIST}
	@${FIND} ${WRKSRC}/ -type f | \
		${SED} -e "s:^${WRKSRC}/:lib/pyla/:g" >> ${PLIST}
	@${FIND} -d ${WRKSRC} -type d | \
		${SED} -e "s:^${WRKSRC}:@dirrm lib/pyla:g" >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL} -m755 ${WRKDIR}/pyla.sh ${PREFIX}/bin/pyla
	${TAR} -C ${WRKSRC} --exclude CVS -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -

.include <bsd.port.post.mk>
