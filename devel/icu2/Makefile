# New ports collection makefile for:    icu2
# Date created:		18 Jan 2002
# Whom:			andrew@ids.pl
#
# $FreeBSD$
#

PORTNAME=	icu
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	http://oss.software.ibm.com/icu/download/2.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andrew@ids.pl
COMMENT=	International Components for Unicode

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-threads=no

INSTALLS_SHLIB= yes

WRKSRC=		${WRKDIR}/icu/source

.include <bsd.port.mk>
