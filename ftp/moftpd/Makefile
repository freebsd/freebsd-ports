# New ports collection makefile for:	moftpd
# Date created:				Mar 19, 2004
# Whom:					Clement Laforet <clement@FreeBSD>org>
#
# $FreeBSD$
#

PORTNAME=	moftpd
PORTVERSION=	1.2.3
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.morth.org/moftpd/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	clement

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A powerful FTP server supporting IPv6, TLS, and much more

USE_AUTOCONF_VER=259
USE_GMAKE=	yes
USE_RC_SUBR=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ENV+=	LIBS="${LIBS}" CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--localstatedir=/var

MAN8=		moftpd.8 moftpadmin.8
LIBS+=		-lcrypt
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.if defined(WITHOUT_TLS)
CONFIGURE_ARGS+=	--without-tls
.elif defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--without-openssl
LIB_DEPENDS+=		gnutls.12:${PORTSDIR}/security/gnutls
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

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
                ${FILESDIR}/moftpd.sh > ${WRKDIR}/moftpd.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/moftpd.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
