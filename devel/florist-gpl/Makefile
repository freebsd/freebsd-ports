# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	florist-gpl
PORTVERSION=	2012
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	draco@marino.st
COMMENT=	POSIX Ada binding, IEEE Standards 1003.5(b,c)

LICENSE=	GPLv3

USES=		ada
GNU_CONFIGURE=	yes
DESTINY=	${WRKDIR}/destino
MAKE_ENV+=	DESTDIR=${DESTINY}

post-extract:
	${CP} ${FILESDIR}/pconfig.* ${WRKSRC}/configs

post-install:
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/

.include <bsd.port.mk>
