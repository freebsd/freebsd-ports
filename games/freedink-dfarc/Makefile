# New ports collection makefile for:	syncterm
# Date created:		3 October 2006
# Whom:			shurd
#
# $FreeBSD$
#

PORTNAME=	freedink-dfarc
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	freedink
DISTNAME=	dfarc-${PORTVERSION}

MAINTAINER=	shurd@sasktel.net
COMMENT=	Frontend and .dmod installer for GNU FreeDink

LIB_DEPENDS=	iconv:${PORTSDIR}/textproc/intltool

USE_GMAKE=	yes
USE_WX=		2.6+
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG} --disable-upx --disable-static

MAN1=		dfarc.1

.include <bsd.port.mk>
