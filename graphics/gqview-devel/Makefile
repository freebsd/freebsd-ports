# New ports collection makefile for:	gqview-devel
# Date Created:				5 March 2003
# Whom:					Andrew Dolgov <cthulhu@cthulhu.ru>
# based on graphics/gqview port
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION=	1.3.9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Another gtk2-based graphic file viewer

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

CONFLICTS=	gqview-1.2.*

MAN1=		gqview.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
