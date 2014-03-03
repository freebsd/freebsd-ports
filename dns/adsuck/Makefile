# Created by: Philippe Pepiot <phil@philpep.org>
# $FreeBSD$

PORTNAME=	adsuck
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://opensource.conformal.com/snapshots/adsuck/ \
		http://philpep.org/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	phil@philpep.org
COMMENT=	DNS relay for ad blocking

LICENSE=	BSD

LIB_DEPENDS+=	libevent-1.4.so:${PORTSDIR}/devel/libevent \
		ldns:${PORTSDIR}/dns/ldns

USE_RC_SUBR=	adsuck

USERS=	_adsuck
GROUPS=	_adsuck

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adsuck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/files/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
