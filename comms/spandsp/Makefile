# New ports collection makefile for:	spandsp
# Date created:		23 June 2005
# Whom:			wlloyd@slap.net
#
# $FreeBSD$
#

PORTNAME=	spandsp
DISTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/ \
		http://www.soft-switch.org/downloads/spandsp/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fax DSP library for Asterisk

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/pre.*$//}

USE_GMAKE=	yes

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -name *.c | ${XARGS} ${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|'

.include <bsd.port.mk>
