# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	tinyq
# Date created:		2003-01-25
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	tinyq
PORTVERSION=	3.0.6
PORTREVISION=	1
PORTEPOCH=	0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@freebsd.org
COMMENT=	A stripped down version of Qt 3 for use as a utility library

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-thread -stl
CONFIGURE_ENV+=	QTDIR="${WRKSRC}"
MAKE_ENV+=	QTDIR="${WRKSRC}"
INSTALLDIR=	${PREFIX}/tinyq
NO_FILTER_SHLIBS=yes

.include <bsd.port.mk>
