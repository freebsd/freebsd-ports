# New ports collection makefile for:	upnp
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	upnp
PORTVERSION=	1.6.6
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/pupnp
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit

CONFLICTS=	upnp-1.0.*
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if defined(NOPORTDOCS)
CONFIGURE_ARGS=	--without-documentation
.else
CONFIGURE_ARGS=	--with-documentation=${DOCSDIR}

PORTDOCS=	*
.endif

.include <bsd.port.mk>
