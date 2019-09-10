# $FreeBSD$

PORTNAME=	at-spi2-core
PORTVERSION=	2.28.0
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	accessibility linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Assistive technology service provider interface (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL20+

RUN_DEPENDS=	at-spi2-core>=2.28.0:accessibility/at-spi2-core

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
.for d in etc usr/lib/systemd usr/libexec usr/share/dbus-1 usr/share/defaults
	@${RM} -r ${WRKSRC}/${d}
.endfor

.include <bsd.port.mk>
