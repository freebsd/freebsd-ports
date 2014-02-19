# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ironsides
PORTVERSION=	20130315
CATEGORIES=	dns
MASTER_SITES=	http://ironsides.martincarlisle.com/
DISTFILES=	trunk${PORTVERSION}.zip

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Authoritative DNS server formally verified by SPARK/Ada	

LICENSE=	Ironsides
LICENSE_NAME=	IRONSIDES - Free software, unlimited redistribution
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/spark2012/spark.ads:${PORTSDIR}/devel/libspark2012

USES=		ada dos2unix
DOS2UNIX_FILES=	dfcs.usafa.edu.zonefile

post-extract:
	@${MV} ${WRKDIR}/trunk ${WRKSRC}
	@(cd ${WRKSRC}; ${RM} *.bak *.bk.[0-9] *.o *.ali)
	@${CP} ${FILESDIR}/ironsides.gpr ${FILESDIR}/Makefile ${WRKSRC}/

.include <bsd.port.mk>
