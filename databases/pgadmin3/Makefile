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
MASTER_SITE_SUBDIR= pgadmin3/release/v${PORTVERSION}/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

USE_PGSQL=	yes
BROKEN_WITH_PGSQL=	73
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx=${X11BASE} --with-wx-config=${WX_CONFIG}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"
CONFLICTS=	pgadmin3-1.[12]*

LIB_DEPENDS+=	wx_gtk2u_stc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-unicode-contrib
WX_CONFIG=	wxgtk2u-2.6-config

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		requires wchar_t 
.endif

.include <bsd.port.post.mk>
