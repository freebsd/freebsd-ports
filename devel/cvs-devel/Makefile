# New ports collection makefile for:	cvs+ipv6
# Date created:	Tue Jul 23 11:24:24 JST 2002
# Whom:		sumikawa
#
# $FreeBSD$
#

PORTNAME=	cvs+ipv6
PORTVERSION=	1.11.5
CATEGORIES=	devel ipv6
MASTER_SITES=	http://ftp.cvshome.org/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/cvs/&,}
MASTER_SITE_SUBDIR=	cvs-${PORTVERSION}
DISTNAME=	cvs-${PORTVERSION}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cvs-1.11.5-v6-20030123.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org

GNU_CONFIGURE=	yes
#USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --without-gssapi

MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8

CVS_SITE?=	:pserver:anoncvs@anoncvs.FreeBSD.org:/home/ncvs
CVS_VER?=	v1_11_5

USE_REINPLACE= yes

post-patch:
	${REINPLACE_CMD} 's/${PORTVERSION:S/./\./g}/&+IPv6/g' ${WRKSRC}/configure
	@${CP} ${FILESDIR}/missing ${WRKSRC}

replace:
.for f in cvs cvsbug
	${MV} /usr/bin/${f} /usr/bin/${f}.orig
	${CP} -p ${PREFIX}/bin/${f} /usr/bin/
.endfor

generate-patch:
	cvs -Rl -d ${CVS_SITE} rdiff -u -r ${CVS_VER} -r HEAD \
	  src/contrib/cvs \
	| ${SED} \
	  -e 's,^\+\+\+ src/contrib/cvs/,+++ ,' \
	  -e 's,^Index: src/contrib/cvs/,Index: ,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  > ${FILESDIR}/patch-freebsdlocal
	cvs -Rl -d ${CVS_SITE} rdiff -u -D 1999-12-01 -r HEAD \
	  gnu/usr.bin/cvs/cvs/prepend_args.c \
	  gnu/usr.bin/cvs/cvs/prepend_args.h \
	| ${SED} \
	  -e 's,^\+\+\+ src/gnu/usr.bin/cvs/cvs/,+++ src/,' \
	  -e 's,^Index: src/gnu/usr.bin/cvs/cvs/,Index: src/,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  >> ${FILESDIR}/patch-freebsdlocal

.include <bsd.port.mk>
