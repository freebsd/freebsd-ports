# ex:ts=8
# Ports collection makefile for:	argtable
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argtable
PORTVERSION=	2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ANSI C library for parsing GNU style command line arguments

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_GETOPT_LONG=	yes
WRKSRC=		${WRKDIR}/argtable2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN3=	argtable2.3

.include <bsd.port.mk>
