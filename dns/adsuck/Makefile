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

LIB_DEPENDS+=	event-1.4:${PORTSDIR}/devel/libevent \
		ldns:${PORTSDIR}/dns/ldns

USE_RC_SUBR=	adsuck

USERS=	_adsuck
GROUPS=	_adsuck

SUB_FILES+=	pkg-message

MAN8=	adsuck.8
MANCOMPRESSED=	yes

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/adsuck ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/${MAN8}.gz ${MANPREFIX}/man/man8/

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/files/* ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
