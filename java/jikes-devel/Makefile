# New ports collection makefile for:    jikes
# Date created:         09 December 1998
# Whom:                 Matthew Dillon <dillon@backplane.com>
#
# $FreeBSD$
#

PORTNAME=	jikes
PORTVERSION=	1.18
CATEGORIES=	java
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/${PORTVERSION}/

MAINTAINER=	archie@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libicuuc.a:${PORTSDIR}/devel/icu

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		CPPFLAGS="-D_THREAD_SAFE -I${PREFIX}/include" \
		LDFLAGS="-pthread -L${PREFIX}/lib"

MAN1=		jikes.1

PLIST_SUB=	PORTVERSION=${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

.include <bsd.port.mk>
