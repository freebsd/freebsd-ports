# New ports collection makefile for:    python
# Version required:     1.4
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.7 1996/10/14 23:14:37 asami Exp $
#

DISTNAME=       python1.4
PKGNAME=        python-1.4
CATEGORIES+=	lang
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/

MAINTAINER=	jkh@FreeBSD.org

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

WRKSRC=		${WRKDIR}/Python-1.4
HAS_CONFIGURE=	yes

MAKE_FLAGS+=	'OPT=${CFLAGS}'
INSTALL_TARGET=	install

post-configure:
	cp ${FILESDIR}/Setup ${WRKSRC}/Modules

post-install:
	strip ${PREFIX}/bin/python
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/python.1
.endif

.include <bsd.port.mk>
