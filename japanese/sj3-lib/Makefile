# New ports collection makefile for:	SJ3
# Date created:		18 Aug 1998
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	sj3
PORTVERSION=	2.0.1.20
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/ \
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork

PATCH_SITES=	http://oikumene.que.ne.jp/misc/
PATCHFILES=	${PORTNAME}-patches-20040916.bz2

MAINTAINER=	hiroo+freebsd@oikumene.gcd.org
COMMENT=	A Japanese input method

BUILD_DEPENDS=	xmkmf:${X_IMAKE_PORT}

MAN1=		sj3.1 sj3dic.1 sj3mkdic.1 sj3serv.1
MANLANG=	ja

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/sj3.sh

# This port requires xmkmf but installs in /usr/local
#
# NOTE : You must not use 'xmkmf -a', because the running 'make depend' caused a error.

.include <bsd.port.pre.mk>

do-configure:
	( cd $(WRKSRC) ; xmkmf ; make Makefiles )

post-install:
	if [ ! -f ${STARTUP_SCRIPT} ]; then 				\
		${ECHO_MSG} "Installing ${STARTUP_SCRIPT} startup file."; 	\
		${INSTALL_SCRIPT} ${FILESDIR}/sj3.sh.in ${STARTUP_SCRIPT};	\
	fi
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
