# ex:ts=8
# Ports collection makefile for:	dbh
# Date created:			Aug 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbh
PORTVERSION=	1.0.14
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Disk Based Hashtables

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
