# Created by: hm
# $FreeBSD$

PORTNAME=	mlan3
PORTVERSION=	1.00
CATEGORIES=	comms
MASTER_SITES=	http://files.maximintegrated.com/sia_bu/public/
DISTNAME=	owpd300b

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Version 3.00 beta API for Dallas Semiconductors 1-wire lan devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

NO_WRKSUBDIR=	yes
USES=		dos2unix uidfix zip
DOS2UNIX_GLOB=	*.c *.h

post-patch:
	@${REINPLACE_CMD} -e '/int main/s/short argc/int argc/' \
		${WRKSRC}/apps/gethumd/gethumd.c ${WRKSRC}/apps/shaapp/shaapp.c

.include <bsd.port.mk>
