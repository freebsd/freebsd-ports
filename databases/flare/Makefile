# New ports collection makefile for:	flare
# Date created:				2010-05-29
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flare
PORTVERSION=	1.0.9
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://labs.gree.jp/data/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Flare - distributed, and persistent key-value storage

LIB_DEPENDS=	boost_program_options.4:${PORTSDIR}/devel/boost-libs \
		tokyocabinet.9:${PORTSDIR}/databases/tokyocabinet

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_KQUEUE" LDFLAGS=-L${LOCALBASE}/lib

USE_RC_SUBR=	flared.sh flarei.sh
SUB_FILES=	pkg-message
MAKE_JOBS_SAFE=	yes

post-install:
	@${INSTALL} -d ${_BINOWNGRP} -m 0750 /var/db/flare
	@${INSTALL_DATA} ${WRKSRC}/etc/flared.conf ${PREFIX}/etc/flared.conf-dist
	@[ -f ${PREFIX}/etc/flared.conf ] || \
		${CP} -p ${PREFIX}/etc/flared.conf-dist ${PREFIX}/etc/flared.conf
	@${INSTALL_DATA} ${WRKSRC}/etc/flarei.conf ${PREFIX}/etc/flarei.conf-dist
	@[ -f ${PREFIX}/etc/flarei.conf ] || \
		${CP} -p ${PREFIX}/etc/flarei.conf-dist ${PREFIX}/etc/flarei.conf
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

# NOT TESTED YET
#CONFIGURE_ARGS+=--enable-mysql-replication
#CONFIGURE_ARGS+=--enable-flarefs --with-fuse=${LOCALBASE}
#CONFIGURE_ARGS+=--enable-memory-allocation-check

.include <bsd.port.post.mk>
