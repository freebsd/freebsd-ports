# New ports collection makefile for:    python
# Version required:     1.4
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.16 1997/08/06 06:40:27 tg Exp $
#

DISTNAME=       python1.4
PKGNAME=        python-1.4
CATEGORIES=	lang tk80
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/ \
		ftp://www.python.org/pub/python/contrib/Graphics/Tkinter/ \
		ftp://ftp.cwi.nl/pub/python/contrib/Graphics/Tkinter/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} _tkinter1.4.c

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11/tk80

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/Python-1.4
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-readline
MAKE_FLAGS+=	'OPT=${CFLAGS}'
INSTALL_TARGET=	install
MAN1=		python.1

#
# If you want to use Python's thread module, you need to set WITH_THREADS
# to 'yes', and you must have the FreeBSD threading c library (libc_r)
# installed. See 'man 3 pthread' for details on libc_r.
#
WITH_THREADS=	yes
SETUP_FILE=	Setup
.if exists(/usr/lib/libc_r.a) && defined(WITH_THREADS) && ${WITH_THREADS} == yes
CONFIGURE_ARGS+=	--with-thread
SETUP_FILE=	Setup.thread
.endif

post-extract:
	${CP} ${DISTDIR}/_tkinter1.4.c ${WRKSRC}/Modules/_tkinter.c

post-configure:
	${CP} ${FILESDIR}/${SETUP_FILE} ${WRKSRC}/Modules/Setup

post-install:
	strip ${PREFIX}/bin/python

.include <bsd.port.mk>
