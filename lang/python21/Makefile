# New ports collection makefile for:    python
# Version required:     1.4
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.17 1997/08/29 07:04:17 tg Exp $
#

DISTNAME=       python1.4
PKGNAME=        python-1.4
CATEGORIES=	lang tk80
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/ \
		ftp://www.python.org/pub/python/contrib/Graphics/Tkinter/ \
		ftp://ftp.cwi.nl/pub/python/contrib/Graphics/Tkinter/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${TKINTER}

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	${TK_DEPENDS}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/Python-1.4
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-readline
MAKE_FLAGS+=	'OPT=${CFLAGS}'
INSTALL_TARGET=	install
MAN1=		python.1

#
# The standard setup file
#
SETUP_FILE=	Setup

#
# Support for Tk is compiled in by default.
#
WITH_TK?=	yes
.if defined(WITH_TK) && $(WITH_TK) == yes
TK_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11/tk80
TKINTER=	_tkinter1.4.c
SETUP_LOCAL+=	Setup.tk
.endif

#
# If you want to use Python's thread module, you need to set WITH_THREADS
# to 'yes', and you must have the FreeBSD threading c library (libc_r)
# installed. See 'man 3 pthread' for details on libc_r.
#
WITH_THREADS?=	yes
.if exists(/usr/lib/libc_r.a) && defined(WITH_THREADS) && ${WITH_THREADS} == yes
CONFIGURE_ARGS+=	--with-thread
SETUP_LOCAL+=	Setup.thread
.endif

post-extract:
.if defined(WITH_TK) && $(WITH_TK) == yes
	${CP} ${DISTDIR}/_tkinter1.4.c ${WRKSRC}/Modules/_tkinter.c
.endif

post-configure:
	${CP} ${FILESDIR}/${SETUP_FILE} ${WRKSRC}/Modules/Setup
.for file in ${SETUP_LOCAL}
	${CAT} ${FILESDIR}/${file} >> ${WRKSRC}/Modules/Setup.local
.endfor

post-install:
	strip ${PREFIX}/bin/python

.include <bsd.port.mk>
