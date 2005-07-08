# New ports collection makefile for:	joe-devel
# Date created:		25 Jul 2001
# Whom:			dwcjr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	joe
PORTVERSION=	3.2
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-editor
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Development version of Joe's Own Editor

CONFLICTS=	joe-2.*
LATEST_LINK=	joe-devel

RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell

USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

ALL_TARGET=	${PORTNAME}
MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

post-install:
.for file in jmacsrc jpicorc jstarrc rjoerc joerc
.if !exists(${PREFIX}/etc/${PORTNAME}/${file})
	@${CP} ${PREFIX}/etc/${PORTNAME}/${file} ${PREFIX}/etc/${PORTNAME}/${file}.dist
.endif
.endfor

.include <bsd.port.post.mk>
