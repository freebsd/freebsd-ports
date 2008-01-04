# New ports collection makefile for:	spandsp-devel
# Date created:		2007-01-13
# Whom:			Joe Holden <joe@joeholden.co.uk>
#
# $FreeBSD$
#

PORTNAME=	spandsp
PORTVERSION=	0.0.4.p15
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/ \
		ftp://ftp.rewt.org.uk/pub/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	A DSP library and software FAX machine

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/spandsp-${PORTVERSION:S/.p15//}
USE_AUTOTOOLS=	libtool15
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_LDCONFIG=	yes

CONFLICTS=	spandsp-[0-9]*

.include <bsd.port.mk>
