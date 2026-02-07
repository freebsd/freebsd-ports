PORTNAME=	dns-blackhole
PORTVERSION=	0.1.0
CATEGORIES=	dns

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Send ads and trackers to a dead-end
WWW=		https://github.com/morganwdavis/dns-blackhole

USE_GITHUB=	yes
GH_ACCOUNT=	morganwdavis

NO_BUILD=	yes

BINFILES=	dns-blackhole.sh
CONFFILES=	dns-blackhole.conf
DBFILES=	allowed_hosts blocked_hosts

PERIODIC=	${PREFIX}/etc/periodic/daily

SUB_FILES=	901.dns-blackhole
PLIST_SUB=	PERIODIC=${PERIODIC}

do-install:
		${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PERIODIC}

.for f in ${BINFILES}
		${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.for f in ${CONFFILES}
		${REINPLACE_CMD} -e "s:%%PORTNAME%%:${PORTNAME}:g" ${WRKSRC}/${f}.dist
		${INSTALL_DATA} ${WRKSRC}/${f}.dist ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.for f in ${DBFILES}
		${INSTALL_DATA} ${WRKSRC}/${f}.dist ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

		${INSTALL_SCRIPT} ${WRKDIR}/901.dns-blackhole ${STAGEDIR}${PERIODIC}/

.include <bsd.port.mk>
