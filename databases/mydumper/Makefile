# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mydumper
PORTVERSION=	0.5.2
CATEGORIES=	databases
MASTER_SITES=	http://code.launchpad.net/mydumper/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	gslin@gslin.org
COMMENT=	MySQL Data Dumper

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}

PLIST_FILES=	sbin/mydumper sbin/myloader
USE_GNOME=	glib20
USE_MYSQL=	yes
USES=		cmake pkgconfig

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mydumper ${WRKSRC}/myloader ${PREFIX}/sbin

.include <bsd.port.mk>
