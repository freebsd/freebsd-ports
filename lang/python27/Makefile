# New ports collection makefile for:    python
# Version required:     1.2
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.1.1.1 1995/08/08 22:09:06 jkh Exp $
#

DISTNAME=       python1.2
PKGNAME=        python-1.2
CATEGORIES+=	languages
MASTER_SITES=	ftp://www.python.org/pub/python/src/

MAINTAINER=	jkh@FreeBSD.org

LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

post-configure:
	cp ${FILESDIR}/Setup ${WRKSRC}/Modules

pre-install:
	cd ${WRKSRC}; ${MAKE} libinstall

WRKSRC=		${WRKDIR}/Python-1.2
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
