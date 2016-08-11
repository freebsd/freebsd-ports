# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	nas-libs
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	audio linux
MASTER_SITES=	EPEL
DISTNAME=	nas-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Audio System (Linux CentOS ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs

RPMVERSION=	7.el6
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/nas-${PORTVERSION}
DESCR=		${.CURDIR}/../nas/pkg-descr

post-extract:
	@${RM} -r ${WRKSRC}/usr/bin ${WRKSRC}/etc/rc.d ${WRKSRC}/etc/sysconfig

.include <bsd.port.mk>
