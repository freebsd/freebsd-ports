PORTNAME=	dns2blackhole
PORTVERSION=	0.1
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	dns2blackhole1@a1poweruser.com
COMMENT=	Malware Prevention through Domain Blocking

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
.for f in dns2blackhole-update1 dns2blackhole-update2 dns2blackhole-sanitize \
	dns2blackhole-sort-fqdn dns2blackhole-whitelist
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/dns2blackhole-unbound.conf \
		${STAGEDIR}${ETCDIR}/dns2blackhole-unbound.conf.sample

	${INSTALL_MAN} ${WRKSRC}/dns2blackhole.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
