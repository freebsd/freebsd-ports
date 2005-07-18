# ex:ts=8
# Ports collection makefile for:	rexx-curl
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	1.3
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rexx${PORTNAME}
PKGNAMEPREFIX=	rexx-
DISTNAME=	RexxCURL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	External function package providing an interface to the cURL package

BUILD_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina
LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-rexx=regina
INSTALLS_SHLIB=	yes

DATADIR=	${PREFIX}/share/rexx${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's| -lc | |g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
