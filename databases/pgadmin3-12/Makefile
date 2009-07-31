# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.2.2
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	pgadmin3/release/v${PORTVERSION}/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

USE_PGSQL=	yes
USE_WX=		2.6
WX_COMPS=	contrib
WX_CONF_ARGS=	relative
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"
CONFLICTS=	pgadmin3-1.[456789]*
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if defined(WX_UNICODE)
PKGNAMESUFFIX=	-unicode
PKGMESSAGE=	${PKGDIR}/pkg-message-unicode

post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
