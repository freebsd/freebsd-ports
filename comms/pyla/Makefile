# Created by: Michael Reifenberger (mike@Reifenberger.com)
# $FreeBSD$

PORTNAME=	pyla
PORTVERSION=	1.1.7.1
PORTREVISION=	1
CATEGORIES=	comms python
#MASTER_SITES=	http://www.teamsw.it/pyla/download/
MASTER_SITES=   LOCAL/mr
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyla${PORTVERSION}

MAINTAINER=	mike@Reifenberger.com
COMMENT=	Hylafax client written in Python

#LIB_DEPENDS=	lirc_client.0:comms/lirc

WRKSRC=		${WRKDIR}/${PORTNAME}
DATADIR=	${PREFIX}/lib/pyla

USES=		python shebangfix tar:tgz
SHEBANG_FILES=	faxcover/subst hylaform.py \
		hylaproto.py ldapclass.py \
		pyladebug.py
SHEBANG_LANG=	sed
sed_OLD_CMD=	/bin/sed
sed_CMD=	/usr/bin/sed
PLIST=		${WRKDIR}/pkg-plist

do-build:
	@(cd ${FILESDIR} && ${CP} pyla.sh ${WRKDIR})
	@(cd ${WRKDIR} && ${REINPLACE_CMD} \
		-e "s|%%PREFIX%%|${PREFIX}|g;" \
		-e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|g;" \
		pyla.sh)
	@(cd ${WRKSRC} && ${CP} language.en language.db)

pre-install:
	@${ECHO_CMD} 'bin/pyla' > ${PLIST}
	@${ECHO_CMD} 'lib/pyla/pyla.pyw' >> ${PLIST}
	@${FIND} ${WRKSRC}/ -type f | \
		${SED} -e "s:^${WRKSRC}/:lib/pyla/:g" >> ${PLIST}
	@${FIND} -d ${WRKSRC} -type d -empty | \
		${SED} -e "s:^${WRKSRC}:@dir lib/pyla:g" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/pyla.sh ${STAGEDIR}${PREFIX}/bin/pyla
	${TAR} -C ${WRKSRC} --exclude CVS -cf - . | \
		${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -

.include <bsd.port.mk>
