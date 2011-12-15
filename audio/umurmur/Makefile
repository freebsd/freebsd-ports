# New ports collection makefile for:	umurmur
# Date created:		2011-02-24
# Whom:			Ayumi Mitsui <ayu@commun.jp>
#
# $FreeBSD$
#

PORTNAME=	umurmur
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ayu@commun.jp
COMMENT=	Minimalistic Murmur (Mumble server)

LIB_DEPENDS=	config.10:${PORTSDIR}/devel/libconfig

USE_GMAKE=	yes
USE_OPENSSL=	yes

USE_RC_SUBR=	umurmur

MAKE_ENV+=	TARGET_ARCH=

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all)

pre-su-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

pre-install:
	@${SED} -i '' -e 's|"/etc/|"${PREFIX}/etc/|' ${WRKSRC}/umurmur.conf.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/umurmurd ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/etc/umurmur
	@${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example ${PREFIX}/etc/umurmur/umurmur.conf.sample
	@if [ ! -f ${PREFIX}/etc/umurmur/umurmur.conf ]; then \
		${CP} -p ${PREFIX}/etc/umurmur/umurmur.conf.sample ${PREFIX}/etc/umurmur/umurmur.conf; \
	fi

.include <bsd.port.post.mk>
