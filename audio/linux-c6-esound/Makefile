# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	esound
PORTVERSION=	0.2.41
PORTREVISION=	3
CATEGORIES=	audio linux
LIB_DISTFILES=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of esound (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-esound-[0-9]* linux-f10-esound-[0-9]*

LINUX_NAME=	${PORTNAME}-libs
RPMVERSION=	3.1.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	libaudiofile
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.LIB ChangeLog NEWS README TIPS TODO esound.sgml
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
