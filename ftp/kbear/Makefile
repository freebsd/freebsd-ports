# New ports collection makefile for:	kbear
# Date created:			Wed May 29 18:10:01 PDT 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		kbear
PORTVERSION=		2.0
CATEGORIES=		ftp kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION}.src

MAINTAINER=		arved@FreeBSD.org

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
INSTALLS_SHLIB=		yes
USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		XML2POT=${TRUE} PO2XML=${TRUE}

.include <bsd.port.mk>
