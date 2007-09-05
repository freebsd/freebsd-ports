# New ports collection makefile for:	libticonv
# Date created:		5 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticonv
PORTVERSION=	1.0.4
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp
DISTFILES=	tilibs2-20070829${EXTRACT_SUFX}

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator character set library

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_ICONV=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/tilibs2/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	@${CHMOD} 755 ${WRKSRC}/install-sh

.include <bsd.port.post.mk>
