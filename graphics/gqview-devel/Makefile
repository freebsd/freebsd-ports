# New ports collection makefile for:	gqview-devel
# Date Created:				5 March 2003
# Whom:					Andrew Dolgov <cthulhu@cthulhu.ru>
# based on graphics/gqview port
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION= 1.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX= -devel

MAINTAINER= cthulhu@cthulhu.ru
COMMENT= Another gtk2-based graphic file viewer

LIB_DEPENDS= png.5:${PORTSDIR}/graphics/png \
			gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

MAN1=		gqview.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gqview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gqview
.endif

.include <bsd.port.post.mk>
