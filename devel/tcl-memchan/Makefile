# New ports collection makefile for:	TclTrf
# Date created:			May 22, 2000
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	memchan
PORTVERSION=	2.1p3
CATEGORIES=	devel tcl83
MASTER_SITES=	http://www.oche.de/~akupries/soft/memchan/download/
PKGNAMEPREFIX=	tcl-
DISTNAME=	memchan${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	tclsh${TCLV}:${PORTSDIR}/lang/tcl${TCLVND}
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_BZIP2=	yes
USE_OPENSSL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/unix

GNU_CONFIGURE=	yes
PLIST_SUB+=	TCLV=${TCLV} TCLVND=${TCLVND}
CONFIGURE_ARGS=	--with-tcl-include-dir=${PREFIX}/include/tcl${TCLV} \
		--with-tcl-lib-dir=${PREFIX}/lib/tcl${TCLV}

#ALL_TARGET=	library

TCLV?=		8.3
TCLVND=		${TCLV:S/.//}
DDIR=		${PREFIX}/lib/tcl${TCLV}/Trf

do-install:
	${MKDIR} ${PREFIX}/lib/tcl${TCLV}/memchan
	${INSTALL_DATA} ${WRKSRC}/libmemchan.so.1 ${PREFIX}/lib/
	${SED} 's@%%PREFIX%%@${PREFIX}@g' < ${FILESDIR}/pkgIndex.tcl \
		> ${PREFIX}/lib/tcl${TCLV}/memchan/pkgIndex.tcl
.ifndef(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/memchan
	${CP} -pR ${WRKSRC}/../doc/html/* ${PREFIX}/share/doc/memchan/

PLIST_SUB+=	DOC=''
.else
PLIST_SUB+=	DOC='@comment '
.endif

.include <bsd.port.mk>
