# New ports collection makefile for:    python
# Version required:     1.4
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.10 1996/11/17 06:12:49 obrien Exp $
#

DISTNAME=       python1.4
PKGNAME=        python-1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/ \
		ftp://www.python.org/pub/python/contrib/Graphics/Tkinter/ \
		ftp://ftp.cwi.nl/pub/python/contrib/Graphics/Tkinter/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} PyTix-1.12.tar.gz

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41 \
		tix4141\\.1\\.:${PORTSDIR}/x11/tix

WRKSRC=		${WRKDIR}/Python-1.4
HAS_CONFIGURE=	yes

MAKE_FLAGS+=	'OPT=${CFLAGS}'
INSTALL_TARGET=	install
MAN1=		python.1

PYTIXSRC=	${WRKDIR}/PyTix-1.12

post-extract:
	@${ECHO_MSG} "===>   Add PyTix extensions to Python core"
	${CP} ${PYTIXSRC}/Tkinter.py ${WRKSRC}/Lib/tkinter
	${CP} ${PYTIXSRC}/Tix.py ${WRKSRC}/Lib/tkinter
	${CP} ${PYTIXSRC}/_tkinter.c ${WRKSRC}/Modules

post-configure:
	${CP} ${FILESDIR}/Setup ${WRKSRC}/Modules

post-install:
	strip ${PREFIX}/bin/python

.include <bsd.port.mk>
