# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.4.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	pgadmin3/release/v${PORTVERSION}/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

USE_GETTEXT=	yes
USE_PGSQL=	yes
IGNORE_WITH_PGSQL=	73
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"
CONFLICTS=	pgadmin3-1.[12]*

USE_WX=		2.6
WX_COMPS=	wx contrib
WX_UNICODE=	yes
WX_CONF_ARGS=	relative

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		cannot install: requires wchar_t
.endif

.include <bsd.port.post.mk>
