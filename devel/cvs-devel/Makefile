# New ports collection makefile for:	cvs+ipv6
# Date created:	Tue Jul 23 11:24:24 JST 2002
# Whom:		sumikawa
#
# $FreeBSD$
#

PORTNAME=	cvs
PORTVERSION=	1.11.17
CATEGORIES=	devel ipv6
MASTER_SITES=	http://musthave.sunbase.org/progs/ccvs/ \
		http://keyserver.kjsl.com/~jharris/distfiles/
PKGNAMESUFFIX=	+ipv6

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	${DISTNAME}-v6-20040610.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=		IPv6 enabled cvs.  You can use IPv6 connection when using pserver

CONFLICTS=	cvsnt-[12]*

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
#USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --without-gssapi \
		--with-editor="vi" \
		--with-tmpdir="/tmp"

MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8
INFO=		cvs cvsclient

CVS_SITE?=	:pserver:anoncvs@anoncvs.jp.FreeBSD.org:/home/ncvs
CVS_VER?=	v${PORTVERSION:S/./_/g}

post-patch:
	${REINPLACE_CMD} 's/${PORTVERSION:S/./\./g}/&+IPv6/g' ${WRKSRC}/configure
	@${CP} ${FILESDIR}/missing ${WRKSRC}

replace:
.for f in cvs cvsbug
	${MV} /usr/bin/${f} /usr/bin/${f}.orig
	${CP} -p ${PREFIX}/bin/${f} /usr/bin/
.endfor

generate-patch:
	cvs -R -d ${CVS_SITE} rdiff -u -r ${CVS_VER} -r HEAD \
	  src/contrib/cvs \
	| ${SED} \
	  -e 's,^\+\+\+ src/contrib/cvs/,+++ ,' \
	  -e 's,^Index: src/contrib/cvs/,Index: ,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  > ${FILESDIR}/patch-freebsdlocal
	cvs -R -d ${CVS_SITE} rdiff -u -D 1999-12-01 -r HEAD \
	  gnu/usr.bin/cvs/cvs/prepend_args.c \
	  gnu/usr.bin/cvs/cvs/prepend_args.h \
	| ${SED} \
	  -e 's,^\+\+\+ src/gnu/usr.bin/cvs/cvs/,+++ src/,' \
	  -e 's,^Index: src/gnu/usr.bin/cvs/cvs/,Index: src/,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  >> ${FILESDIR}/patch-freebsdlocal

.include <bsd.port.mk>
