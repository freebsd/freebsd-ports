# New ports collection makefile for:    Scheme-to-C
# Version required:     15mar93
# Date created:         28 Dec 1994
# Whom:                 jmacd@uclink.berkeley.edu
#
# $FreeBSD$
#

DISTNAME= 	schemetoc-93.3.15
PKGNAME=	schemetoc-93.3.15
CATEGORIES=	lang
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/DEC/Scheme-to-C/
DISTFILES=      15mar93.tar.Z

MAINTAINER=	jmacd@FreeBSD.org

BROKEN_ELF=	yes

USE_XLIB=	yes
NO_WRKSUBDIR=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
