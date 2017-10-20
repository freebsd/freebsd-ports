# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	dualserver
PORTVERSION=	6.94
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	dns net
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}V${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Combined DHCP/DNS server for small LANs

LICENSE=	GPLv2

DEPRECATED=	Please migrate to dns/dnsmasq. Over the years dualserver becomes unmaintenaible.
EXPIRATION_DATE=	2018-01-01

USES=		dos2unix
USE_RC_SUBR=	dualserver
PLIST_FILES=	sbin/dualserver etc/dualserver.conf.sample

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-build:
	${CXX} ${CXXFLAGS} -o ${WRKSRC}/dualserver \
		${WRKSRC}/dualserverd.cpp -lpthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
