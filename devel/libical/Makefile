# New ports collection makefile for:   libical
# Date created:        8 November 2002
# Whom:                Joe Kelsey
#
# $FreeBSD$
#

PORTNAME=	libical
PORTVERSION=	0.24
PORTREVISION=	3
DISTFILES=	${DISTNAME}.RC4${EXTRACT_SUFX}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freeassociation

MAINTAINER=	joe@zircon.seattle.wa.us
COMMENT=	An implementation of the IETF's Calendaring and Scheduling protocols

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_PYTHON)
CONFIGURE_ARGS=	--enable-python=yes
USE_PYTHON=	yes
PLIST_SUB+=     PYTHON:=""
.else
CONFIGURE_ARGS=	--enable-python=no
PLIST_SUB+=     PYTHON:="@comment "
.endif

.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fPIC"
.endif
.include <bsd.port.post.mk>
