# New ports collection makefile for:    bigloo
# Date created:         15 Jul 2002
# Whom:                 Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	bigloo
PORTVERSION=	2.6b
PORTREVISION=	2
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp-sop.inria.fr/mimosa/fp/Bigloo/ \
		ftp://kaolin.unice.fr/pub/Bigloo/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tacho@daemonz.org
COMMENT=	A Scheme interpreter and native code compiler

USE_GMAKE=	yes
ALL_TARGET=
INSTALL_TARGET=	install compile-bee install-bee
USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
MAN1=		bigloo.1
INFO=		bigloo
PLIST_SUB=	BIGLOO_VERSION=${PORTVERSION}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/bigloo/%%BIGLOO_VERSION%%

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--emacs=${EMACS_NAME} \
		--lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/bigloo \
		--native=yes \
		--jvm=no

INSTALL_INFO?=	install-info

post-patch:
	@${REINPLACE_CMD} -e 's|prefix/doc|prefix/share/doc|' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's/BGL_HAVE_SENDFILE 1/BGL_HAVE_SENDFILE 0/' \
		${WRKSRC}/lib/${PORTVERSION}/bigloo_config.h

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/bigloo.sh | ${SED} "s|%%BIGLOO_VERSION%%|${PORTVERSION}|g" > ${PREFIX}/etc/rc.d/000.bigloo.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/000.bigloo.sh

test: build
	@(cd ${WRKSRC}; ${GMAKE} test)

.include <bsd.port.post.mk>
