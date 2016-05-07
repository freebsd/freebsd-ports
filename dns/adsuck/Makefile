# Created by: Philippe Pepiot <phil@philpep.org>
# $FreeBSD$

PORTNAME=	adsuck
PORTVERSION=	2.3
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://opensource.conformal.com/snapshots/adsuck/ \
		http://philpep.org/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	phil@philpep.org
COMMENT=	DNS relay for ad blocking

LICENSE=	ISCL

LIB_DEPENDS+=	libevent.so:devel/libevent2 \
		libldns.so:dns/ldns

CFLAGS+= 	-I${LOCALBASE}/include

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
