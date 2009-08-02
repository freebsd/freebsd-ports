# New ports collection makefile for:	sphinx3
# Date created:				4 Jan 2008
# Whom:					Richard Neese
#
# $FreeBSD$
#

PORTNAME=	sphinx3
PORTVERSION=	0.7
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cmusphinx

MAINTAINER=	r.neese@gmail.com
COMMENT=	Speech recognition system

LIB_DEPENDS=	sphinxfe.0:${PORTSDIR}/audio/sphinxbase

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=libtool:22

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/sphinxbase" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
