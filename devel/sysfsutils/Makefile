PORTNAME=	sysfsutils
PORTVERSION=	2.1.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/linux-diag/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System Utilities Based on Sysfs
WWW=		https://linux-diag.sourceforge.net/Sysfsutils.html

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		cpe libtool
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
