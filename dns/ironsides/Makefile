# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ironsides
PORTVERSION=	${SNAPSHOT:S/_//g}
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://ironsides.martincarlisle.com/
DISTNAME=	ironsides_authoritative-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Authoritative DNS server formally verified by SPARK/Ada

LICENSE=	Ironsides
LICENSE_NAME=	IRONSIDES - Free software, unlimited redistribution
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/spark2012/spark.ads:devel/libspark2012

USES=		ada dos2unix zip
DOS2UNIX_FILES=	dfcs.usafa.edu.zonefile ironsides.1
SNAPSHOT=	2015_04_15
WRKSRC=		${WRKDIR}/${DISTFILES:S/.zip//}
PLIST_FILES=	sbin/ironsides man/man1/ironsides.1.gz
PORTEXAMPLES=	dfcs.usafa.edu.zonefile

post-extract:
	@${CP} ${FILESDIR}/ironsides.gpr ${FILESDIR}/Makefile ${WRKSRC}/

.include <bsd.port.mk>
