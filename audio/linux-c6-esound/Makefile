# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	esound
PORTVERSION=	0.2.41
PORTREVISION=	2
CATEGORIES=	audio linux
DISTNAME=	${PORTNAME}-libs-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of esound (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-esound-[0-9]* linux-f10-esound-[0-9]*

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libaudiofile
LINUX_NAME=	${PORTNAME}-libs

RPMVERSION=	3.1.el6
USE_LDCONFIG=	yes
SRC_DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.LIB ChangeLog NEWS README TIPS TODO esound.sgml
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
