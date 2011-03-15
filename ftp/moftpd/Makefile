# New ports collection makefile for:	moftpd
# Date created:				Mar 19, 2004
# Whom:					Clement Laforet <clement@FreeBSD>org>
#
# $FreeBSD$
#

PORTNAME=	moftpd
PORTVERSION=	1.2.3
PORTREVISION=	9
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.morth.org/moftpd/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	clement

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful FTP server supporting IPv6, TLS, and much more

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_RC_SUBR=	moftpd
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="${LIBS}" CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--localstatedir=/var
MAKE_JOBS_UNSAFE=	yes

MAN8=		moftpd.8 moftpadmin.8
LIBS+=		-lcrypt

.if defined(WITHOUT_TLS)
CONFIGURE_ARGS+=	--without-tls
.elif defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--without-openssl
LIB_DEPENDS+=		gnutls.40:${PORTSDIR}/security/gnutls
LIBS=			-L${LOCALBASE}/lib -lgnutls
CFLAGS+=		-I${LOCALBASE}/include
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if defined(WITH_MYSQL)
CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib/mysql
.else
CONFIGURE_ARGS+=	--without-sql
.endif

.include <bsd.port.mk>
