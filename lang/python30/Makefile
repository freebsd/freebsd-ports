# New ports collection makefile for:    python
# Version required:     1.2
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.3 1995/11/22 13:13:06 asami Exp $
#

DISTNAME=       python1.3
PKGNAME=        python-1.3
CATEGORIES+=	lang
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/

MAINTAINER=	jkh@FreeBSD.org

LIB_DEPENDS=	tcl74\\.1\\.:${PORTSDIR}/lang/tcl74 \
		tk40\\.1\\.:${PORTSDIR}/x11/tk4

WRKSRC=		${WRKDIR}/Python-1.3
HAS_CONFIGURE=	yes

MAKE_FLAGS+=	'OPT=${CFLAGS}'
INSTALL_TARGET=	install libinstall maninstall

post-configure:
	cp ${FILESDIR}/Setup ${WRKSRC}/Modules

post-install:
	strip ${PREFIX}/bin/python
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/python.1
.endif

.include <bsd.port.mk>
