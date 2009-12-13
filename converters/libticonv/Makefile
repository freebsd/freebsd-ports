# New ports collection makefile for:	libticonv
# Date created:		5 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticonv
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.10
DISTNAME=	tilibs2-20080110

MAINTAINER=	tijl@coosemans.org
COMMENT=	TI calculator character set library

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_ICONV=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/tilibs2/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	@${CHMOD} 755 ${WRKSRC}/install-sh

.include <bsd.port.mk>
