# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	lang python
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	An interpreted object-oriented programming language

DEPRECATED=	"This port will be removed on June 18th 2004."
DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fpectl
CONFIGURE_ENV=	OPT="${CFLAGS}"
INSTALL_TARGET=	altinstall
PLIST=		${WRKDIR}/PLIST
MAN1=		${PYTHON_VERSION}.1

USE_PYTHON=	yes
PYTHON_VERSION=	python2.0
PYTHON_NO_DEPENDS=	yes
LATEST_LINK=	${PYTHON_VERSION:S/.//}

#
# The standard setup file
#
SETUP_FILE=	Setup

#
# If you don't want to use Python's thread module, you need to set
# WITHOUT_THREADS.
#
.if !defined(NOLIBC_R) && !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--with-threads
CFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--without-threads
.endif

#
# OpenSSL support is built on machines that have it
#
.if exists(/etc/ssl/openssl.cnf)
SETUP_LOCAL+=	Setup.OpenSSL
.endif

#
# The mpz module is built on machines with a full source tree
#
.if exists(/usr/src/contrib/libgmp/gmp-impl.h)
SETUP_LOCAL+=	Setup.gmp
PLIST_GMP=	${PKGDIR}/pkg-plist.gmp
.endif

#
# Install the Tools by default. It contains scripts ranging from an IDE
# to a web tree checker, to a collection of simple scripts that are useful
# while extending or managing Python.
#
.if !defined(WITHOUT_TOOLS)
PLIST_TOOLS=	${PKGDIR}/pkg-plist.Tools
.endif

#
# Install Demo/ by default.
#
.if !defined(WITHOUT_DEMO)
PLIST_DEMO=	${PKGDIR}/pkg-plist.Demo
DEMODIR=	${PREFIX}/share/examples/${PYTHON_VERSION}
.endif

post-configure:
	${CP} ${FILESDIR}/${SETUP_FILE} ${WRKSRC}/Modules/Setup
.for file in ${SETUP_LOCAL}
	${CAT} ${FILESDIR}/${file} >> ${WRKSRC}/Modules/Setup.local
.endfor

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if ${OSVERSION} >= 500000 && ${OSVERSION} < 500005
CONFIGURE_ARGS+= --with-libs='-lxpg4'
.endif
.if ${OSVERSION} < 400020
CONFIGURE_ARGS+= --with-libs='-lxpg4'
.endif

.if ${OSVERSION} >= 500000
PLATFORMS=plat-freebsd2 plat-freebsd3 plat-freebsd4
.elif ${OSVERSION} >= 400000
PLATFORMS=plat-freebsd2 plat-freebsd3 plat-freebsd5
.elif ${OSVERSION} >= 300000
PLATFORMS=plat-freebsd2 plat-freebsd4 plat-freebsd5
.else
PLATFORMS=plat-freebsd3 plat-freebsd4 plat-freebsd5
.endif

pre-su-install:
.for platform in ${PLATFORMS}
	${MKDIR} ${PYTHONPREFIX_LIBDIR}/${platform}
.for file in FCNTL.py IN.py SOCKET.py TERMIOS.py regen
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/${file} \
		${PYTHONPREFIX_LIBDIR}/${platform}
.endfor
.endfor
	@${SORT} -r -o ${PLIST} ${PLIST_GMP} ${PLIST_TOOLS} ${PLIST_DEMO} \
		${PKGDIR}/pkg-plist

post-install:
	@${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Misc/python.man \
		${MANPREFIX}/man/man1/${PYTHON_VERSION}.1
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
.if !defined(WITHOUT_TOOLS)
	@cd ${WRKSRC}; tar -c --exclude='*CVS*' -f - Tools | \
		(cd ${PYTHONPREFIX_LIBDIR}; tar xf -)
.endif
.if !defined(WITHOUT_DEMO)
	@${MKDIR} ${DEMODIR}
	@cd ${WRKSRC}/Demo; tar -c --exclude='*CVS*' -f - [M-z]* | \
		(cd ${DEMODIR}; tar xf -)
.endif

.include <bsd.port.post.mk>
