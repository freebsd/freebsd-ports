# ex:ts=8
# Ports collection makefile for:	libassa
# Date created:			Dec 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libassa
PORTVERSION=	3.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An C++ networking library and application framework

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--disable-html-docs --disable-static
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s: doc : :g' ${WRKSRC}/Makefile.in

pre-configure:
	@${CP} ${LTMAIN} ${WRKSRC}

.include <bsd.port.mk>
