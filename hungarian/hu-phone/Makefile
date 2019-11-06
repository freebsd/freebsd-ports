# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	phone
PORTVERSION=	20020622
CATEGORIES=	hungarian
MASTER_SITES=	http://ipv6.niif.hu/~mohacsi/downloads/
PKGNAMEPREFIX=	hu-
DISTNAME=	korzetszam.2002.06.22
EXTRACT_SUFX=	.gz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Phone codes in Hungary / Magyarorszagi korzetszamok

BROKEN=		unfetchable

PLIST_FILES=	share/misc/hu.phone
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/hu.phone
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/hu.phone ${STAGEDIR}${PREFIX}/share/misc

.include <bsd.port.mk>
