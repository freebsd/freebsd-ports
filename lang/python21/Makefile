# New ports collection makefile for:    python
# Version required:     1.4
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.13 1997/04/20 13:19:11 wosch Exp $
#

DISTNAME=       python1.4
PKGNAME=        python-1.4
CATEGORIES=	lang tk41
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/ \
		ftp://www.python.org/pub/python/contrib/Graphics/Tkinter/ \
		ftp://ftp.cwi.nl/pub/python/contrib/Graphics/Tkinter/

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

WRKSRC=		${WRKDIR}/Python-1.4
HAS_CONFIGURE=	yes

MAKE_FLAGS+=	'OPT=${CFLAGS}'
INSTALL_TARGET=	install
MAN1=		python.1

post-configure:
	${CP} ${FILESDIR}/Setup ${WRKSRC}/Modules

post-install:
	strip ${PREFIX}/bin/python

.include <bsd.port.mk>
