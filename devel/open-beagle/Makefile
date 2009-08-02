# ex:ts=8
# Ports collection makefile for:	beagle
# Date created:			Jun 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	open-beagle
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	SF/beagle
DISTNAME=	beagle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Evolutionary Computation Framework

CONFLICTS=	beagle-[0-9]*
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--enable-optimization --with-zlib=/usr
USE_LDCONFIG=	yes
USE_GMAKE=	yes
PACCVERSION=	1.3.1b

PLIST_SUB=	PORTVERSION=${PORTVERSION} PACCVERSION=${PACCVERSION}
BUILD_DEPENDS+=	gsed:${PORTSDIR}/textproc/gsed

#unfortunately, some important sed statements rely on GNU sed behavior, and can't be
#easily changed to call GNU sed by means of the configure script
post-configure:
	${FIND} -X ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} \
	's/sed /gsed /g'

.include <bsd.port.mk>
