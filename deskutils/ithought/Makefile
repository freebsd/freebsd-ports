# New ports collection makefile for: ithought
# Date created:		20 Feb 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ithought
PORTVERSION=	a5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ithought

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible text management system

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/libexec

USE_GNOME=	gtk12

.include <bsd.port.mk>
