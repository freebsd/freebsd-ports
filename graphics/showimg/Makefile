# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.9.4.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/0.9.4-1/
DISTNAME=	showimg-0.9.4-1

MAINTAINER=	shelton@granch.ru
COMMENT=	A picture viewer designed to run under KDE 3.x

LIB_DEPENDS=	kipi:${PORTSDIR}/graphics/libkipi

USE_BZIP2=	yes
USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

MAN1=		showimg.1

CONFIGURE_ARGS+=	--enable-debug=full

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
#	@${REINPLACE_CMD} -e 's|-O2||g' -e "s,-lpthread,${PTHREAD_LIBS},g" \
#		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-O2||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
