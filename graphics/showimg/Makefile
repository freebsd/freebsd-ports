# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.9.5.r.1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/.0.9.5/distributions/SVN_info/
DISTNAME=	showimg-0.9.5-rc1

MAINTAINER=	shelton@granch.ru
COMMENT=	A picture viewer designed to run under KDE 3.x

LIB_DEPENDS=	kipi:${PORTSDIR}/graphics/libkipi \
		kexif:${PORTSDIR}/graphics/libkexif

USE_BZIP2=	yes
USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

CONFIGURE_ARGS+=	--disable-debug

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
