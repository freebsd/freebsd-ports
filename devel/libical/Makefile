# New ports collection makefile for:   libical
# Date created:        8 November 2002
# Whom:                Joe Kelsey
#
# $FreeBSD$
#

PORTNAME=	libical
PORTVERSION=	0.24
DISTFILES=	${DISTNAME}.RC4${EXTRACT_SUFX}
CATEGORIES=	devel
MASTER_SITES=	http://osdn.dl.sourceforge.net/sourceforge/freeassociation/

MAINTAINER=	joe@zircon.seattle.wa.us

BUILD_DEPENDS=	perl:${PORTSDIR}/lang/perl5

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_PYTHON)
CONFIGURE_ARGS=	--enable-python=yes
USE_PYTHON=	yes
PLIST_SUB+=     PYTHON:=""
.else
CONFIGURE_ARGS=	--enable-python=no
PLIST_SUB+=     PYTHON:="@comment "
.endif

.include <bsd.port.mk>
