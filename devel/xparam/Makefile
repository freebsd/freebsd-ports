# ex:ts=8
# New ports collection makefile for:	xparam
# Date created:			Dec 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xparam
PORTVERSION=	1.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A general-purpose tool for parameter handling in C++

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dynamic
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-ldl,,g" ${WRKSRC}/configure

.include <bsd.port.mk>
