# New ports collection makefile for:	big5con
# Date created:		07 Jan 1997
# Whom:			Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	big5con
PORTVERSION=	0.92e
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/source/ \
		ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/binary/
DISTFILES=	big5con-0.92e.tgz b5cbin-pa.tgz

MAINTAINER=	ports@FreeBSD.org

ONLY_FOR_ARCHS=	i386

EXTRACT_ONLY=	${DISTNAME}.tgz
USE_REINPLACE=	yes

# With the help from pa@freebsd.ee.ntu.edu.tw
# +0.92d use kc-fonts, whcih can be included in cdrom, instead of taipei-fonts.
# Note: 0.92c is restricted due to the taipei-fonts-copyright.
# 
# 1999/02/12: 0.92d -> 0.92e
# Fix some bugs
# ftp://bsd.sinica.edu.tw/pub/FreeBSD/taiwan/users/woju/source/b5c-d2e.patch

.include <bsd.port.pre.mk>
post-patch:
.if ${OSVERSION} > 500012
	@${REINPLACE_CMD} -e 's,machine/console.h>,sys/consio.h>\n#include\t<sys/kbio.h>\n,' ${WRKSRC}/include/* ${WRKSRC}/src/*
.endif
pre-install:
	@if [ ! -f ${PREFIX}/lib/fonts/kc16.smf ]; then \
		tar xvfzp ${DISTDIR}/b5cbin-pa.tgz -C ${PREFIX}; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
