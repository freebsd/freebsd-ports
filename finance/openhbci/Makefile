# Ports collection makefile for:	openhbci
# Date created:				Jan 3, 2003
# Whom:					Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$

PORTNAME=		openhbci
PORTVERSION=		0.9.13
PORTREVISION=		1
CATEGORIES=		finance
MASTER_SITES=	 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		heiner@bilch.com
COMMENT=	HBCI is a bank-independent homebanking standard

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=			"Does not compile on FreeBSD >= 5.x"
.endif

.include <bsd.port.post.mk>
