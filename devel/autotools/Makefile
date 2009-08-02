# New ports collection makefile for:	autotools
# Date created:				14th April 2007
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	autotools
PORTVERSION=	20080819
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ade@FreeBSD.org
COMMENT=	Autotools meta-port

RUN_DEPENDS=	libtool:${PORTSDIR}/devel/libtool22

PLIST_FILES=	share/${PORTNAME}
NO_BUILD=	yes
NO_FETCH=	yes

AVAIL_AUTOCONF=	2.13 2.62
AVAIL_AUTOMAKE=	1.4 1.5 1.6 1.7 1.8 1.9 1.10

.for VER in ${AVAIL_AUTOCONF}
RUN_DEPENDS+=	autoconf-${VER}:${PORTSDIR}/devel/autoconf${VER:C/\.//}
.endfor

.for VER in ${AVAIL_AUTOMAKE}
RUN_DEPENDS+=	automake-${VER}:${PORTSDIR}/devel/automake${VER:C/\.//}
.endfor

do-install:
	@${ECHO_CMD} "Placeholder file" > ${PREFIX}/${PLIST_FILES}

.include <bsd.port.mk>
