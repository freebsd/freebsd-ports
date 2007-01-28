# New ports collection makefile for:	spandsp-devel
# Date created:		2007-01-13
# Whom:			Joe Holden <joe@joeholden.co.uk>
#
# $FreeBSD$
#

PORTNAME=	spandsp
DISTVERSION=	0.0.3pre27
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/ \
		ftp://ftp.rewt.org.uk/pub/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	spandsp-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	Fax DSP library

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/spandsp-0.0.3/
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_LDCONFIG=	yes

CONFLICTS=	spandsp-[0-9]*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
