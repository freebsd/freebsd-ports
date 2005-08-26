# New ports collection makefile for:	spandsp
# Date created:		23 June 2005
# Whom:			wlloyd@slap.net
#
# $FreeBSD$
#

PORTNAME=	spandsp
DISTVERSION=	0.0.2pre18
CATEGORIES=	comms
MASTER_SITES=	ftp://soft-switch.org/pub/spandsp/${PORTNAME}-${DISTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fax DSP library for Asterisk

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/pre.*$//}

USE_GMAKE=	yes
USE_REINPLACE=	yes

USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INSTALLS_SHLIB=	yes

post-patch:
	@${FIND} ${WRKSRC} -name *.c | ${XARGS} ${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|'

.include <bsd.port.mk>
