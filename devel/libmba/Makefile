# ex:ts=8
# Ports collection makefile for:	libmba
# Date Created:			Sep 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libmba
PORTVERSION=	0.5.1
CATEGORIES=	devel
MASTER_SITES=	http://www.ioplex.com/~miallen/libmba/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of C modules potentially useful to any project

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

SHLIB_MAJOR=	0
MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}"
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

MAN3=		cfg.3m domnode.3m mbs.3m msgno.3m hashmap.3m hexdump.3m \
		linkedlist.3m pool.3m shellout.3m stack.3m varray.3m
MANCOMPRESSED=	yes

.include <bsd.port.mk>
