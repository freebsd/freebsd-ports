# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	dualserver
PORTVERSION=	6.94
PORTEPOCH=	1
CATEGORIES=	dns net
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}V${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Combined DHCP/DNS server for small LANs

LICENSE=	GPLv2

USES=		dos2unix
USE_RC_SUBR=	dualserver
PLIST_FILES=	sbin/dualserver etc/dualserver.conf.sample

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-build:
	${CXX} ${CXXFLAGS} -o ${WRKSRC}/dualserver \
		${WRKSRC}/dualserverd.cpp ${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
