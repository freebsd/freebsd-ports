# ex:ts=8
# Ports collection makefile for:	gts
# Date created:			Jun 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gts
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erik@smluc.org
COMMENT=	GNU Triangulated Surface Library

USE_GNOME=	glib20 gnometarget pkgconfig
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-release \$$(LT_RELEASE)||g ; s|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|'

.include <bsd.port.mk>
