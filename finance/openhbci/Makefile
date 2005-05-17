# Ports collection makefile for:	openhbci
# Date created:				Jan 3, 2003
# Whom:					Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$

PORTNAME=		openhbci
PORTVERSION=		0.9.17.2
CATEGORIES=		finance
MASTER_SITES=	 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		openhbci-0.9.17-2

MAINTAINER=		heiner@bilch.com
COMMENT=		HBCI is a bank-independent homebanking standard

WRKSRC=			${WRKDIR}/${PORTNAME}-0.9.17
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes
USE_INC_LIBTOOL_VER=	15

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
IGNORE=			does not work on 4.x, needs newer C++ library
.endif

.include <bsd.port.post.mk>
