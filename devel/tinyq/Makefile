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
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	devel kde
MASTER_SITES=	http://savannah.nongnu.org/download/tinyq/

MAINTAINER=	kde@freebsd.org

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-thread -stl
CONFIGURE_ENV+=	QTDIR="${WRKSRC}"
MAKE_ENV+=	QTDIR="${WRKSRC}"
INSTALLDIR=	${PREFIX}/tinyq

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>

#EOF
