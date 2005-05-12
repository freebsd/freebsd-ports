# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR= pgadmin3/release/v${PORTVERSION}/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

USE_PGSQL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx=${X11BASE}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
WITHOUT_UNICODE=	yes
.endif

pre-everything::
.if !defined(WITHOUT_UNICODE)
	@${ECHO_MSG} "You can build non-Unicode version by defining WITHOUT_UNICODE."
.endif

.if !defined(WITHOUT_UNICODE)
LIB_DEPENDS+=	wx_gtk2u_stc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-unicode-contrib
CONFIGURE_ARGS+=--with-wx-config=wxgtk2u-2.6-config
PKGNAMESUFFIX=	-unicode
PKGMESSAGE=	${PKGDIR}/pkg-message-unicode

post-install:
	@${CAT} ${PKGMESSAGE}
.else
LIB_DEPENDS+=	wx_gtk2_stc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-contrib
CONFIGURE_ARGS+=--with-wx-config=wxgtk2-2.6-config
.endif # WITHOUT_UNICODE

.include <bsd.port.post.mk>
