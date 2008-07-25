# New ports collection makefile for:   sphinxbase
# Date created:        8 Jan 2008
# Whom:                r.neese
#
# $FreeBSD$
#

PORTNAME=	sphinxbase
PORTVERSION=	0.3
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cmusphinx

MAINTAINER=	r.neese@gmail.com
COMMENT=	CMU SPhinx Speech recognition system base

USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15 automake:19

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
