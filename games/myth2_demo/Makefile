# New ports collection makefile for:	myth2_demo
# Date created:				2000-01-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	myth2_demo
PORTVERSION=	1.3
CATEGORIES=	games linux
MASTER_SITES=	ftp://ftp.linux.tucows.com/pub/Loki/updates/loki_demos/ \
		ftp://ftp.sunsite.auc.dk/disk1/lokigames/updates/loki_demos/
PKGNAMEPREFIX=	linux-
DISTNAME=	myth2-demo
EXTRACT_SUFX=	.run
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"no license"
NO_CDROM=	${RESTRICTED}
NO_FTP=		${RESTRICTED}
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/update/demos/myth2_demo/

do-extract:
	${MKDIR} ${WRKDIR}
	${SED} -e 1,174d < ${DISTDIR}/${DISTFILES} | ${TAR} -C ${WRKDIR} -xzvf -

do-patch:
	${MKDIR} ${WRKSRC}
	cd ${WRKDIR} && bin/Linux/x86/loki_patch patch.dat ${WRKDIR}/update
	${RM} -f ${WRKSRC}/myth2_demo.ppc
	- ${MV} ${WRKSRC}/README ${WRKDIR}

pre-install:
	${ECHO_CMD} bin/myth2_demo.x86 > ${PLIST}
.ifndef(NOPORTDOCS)
	${ECHO_CMD} share/doc/myth2_demo/README >> ${PLIST}
.endif
	${FIND} ${WRKSRC}/ -type f | \
		${PERL} -pi -e "s:^${WRKSRC}/:lib/myth2_demo/:g" >> ${PLIST}
	${FIND} -d ${WRKSRC}/ -type d | \
		${PERL} -pi -e "s:^${WRKSRC}/:\@dirrm lib/myth2_demo/:g" >> \
			${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/myth2_demo
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README ${DOCSDIR}
.endif
	cd ${WRKSRC} && pax -r -w * ${PREFIX}/lib/myth2_demo
	cd ${PREFIX}/bin && ${LN} -s ../lib/myth2_demo/myth2_demo.x86

.include <bsd.port.mk>
