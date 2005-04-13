# New ports collection Makefile for:	ferite
# Date created:				21 August 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	ferite
PORTVERSION=	0.99.6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An embeddable scripting language

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes
PLIST_SUB=	MACHINE_ARCH=${MACHINE_ARCH}

MAN1=		builder.1 ferite.1

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=${NOPORTDOCS}
.endif

.include <bsd.port.mk>
