# New ports collection makefile for:	ksetiwatch
# Date created:				17 January 2001
# Whom:					Sverre Valgeirsson <sverre@k9k203-3.kam.afb.lu.se>
#
# $FreeBSD$

PORTNAME=	ksetiwatch
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ksetiwatch
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	sverrir@hem.passagen.se
COMMENT=	A monitoring tool for the seti@home client

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/-1//}
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

pre-configure:
	cd ${WRKSRC}; autoconf

.include <bsd.port.mk>
