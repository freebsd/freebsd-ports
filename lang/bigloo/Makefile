# New ports collection makefile for:    bigloo
# Date created:         15 Jul 2002
# Whom:                 Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	bigloo
PORTVERSION=	2.5a
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp-sop.inria.fr/mimosa/fp/Bigloo/ \
		ftp://kaolin.unice.fr/pub/Bigloo/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tacho@daemonz.org

USE_GMAKE=	yes
ALL_TARGET=
INSTALL_TARGET=	install compile-bee install-bee
EMACS_PORT_NAME?=	emacs21
MAN1=		bigloo.1
PLIST_SUB=	BIGLOO_VERSION=${PORTVERSION}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/bigloo/%%BIGLOO_VERSION%%

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--emacs=${EMACS_NAME} \
		--lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/bigloo \
		--native=yes \
		--jvm=no

INSTALL_INFO?=	install-info

post-install: install-info
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/bigloo.sh | ${SED} "s|%%BIGLOO_VERSION%%|${PORTVERSION}|g" > ${PREFIX}/etc/rc.d/000.bigloo.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/000.bigloo.sh

install-info:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME}.info ${PREFIX}/info/dir

test: build
	@(cd ${WRKSRC}; ${GMAKE} test)

.include <bsd.port.mk>
