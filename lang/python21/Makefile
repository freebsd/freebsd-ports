# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	1.6
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/1.6/
DISTNAME=	Python-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

DIST_SUBDIR=	python
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fpectl
CONFIGURE_ENV=	OPT="${CFLAGS}"
INSTALL_TARGET=	install
PLIST=		${WRKDIR}/PLIST
MAN1=		python.1

USE_PYTHON=	yes
PYTHON_VERSION=	python1.6
PYTHON_NO_DEPENDS=	yes

#
# The standard setup file
#
SETUP_FILE=	Setup

#
# If you don't want to use Python's thread module, you need to set
# WITHOUT_THREADS.
#
LIBC_R!=	/sbin/ldconfig -r | grep c_r || true
.if (${LIBC_R} != "") && !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--with-thread
CFLAGS+=		-D_THREAD_SAFE
CONFIGURE_ENV+=		LDFLAGS="-pthread ${LDFLAGS}"
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
PLIST_GMP=	${PKGDIR}/PLIST.gmp
.endif

#
# Install the Tools by default. It contains scripts ranging from an IDE
# to a web tree checker, to a collection of simple scripts that are useful
# while extending or managing Python.
#
.if !defined(WITHOUT_TOOLS)
PLIST_TOOLS=	${PKGDIR}/PLIST.Tools
.endif

post-extract:
	cd ${WRKSRC}/Lib && ${SH} ${FILESDIR}/plat-freebsd4.sh
	cd ${WRKSRC}/Lib && ${SH} ${FILESDIR}/plat-freebsd5.sh

post-configure:
	${CP} ${FILESDIR}/${SETUP_FILE} ${WRKSRC}/Modules/Setup
.for file in ${SETUP_LOCAL}
	${CAT} ${FILESDIR}/${file} >> ${WRKSRC}/Modules/Setup.local
.endfor

.include <bsd.port.pre.mk>

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

pre-install:
.for platform in ${PLATFORMS}
	${MKDIR} ${PREFIX}/lib/${PYTHON_VERSION}/${platform}
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/*                    \
		${PREFIX}/lib/${PYTHON_VERSION}/${platform}/
.endfor
	@sort -r -o ${PLIST} ${PLIST_GMP} ${PLIST_TOOLS} ${PKGDIR}/PLIST

post-install:
	strip ${PREFIX}/bin/python
	@${MKDIR} ${PREFIX}/share/doc/python
	@${MKDIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/Misc/python-mode.el ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/python
	@${MKDIR} ${PREFIX}/lib/${PYTHON_VERSION}/site-packages
.if !defined(WITHOUT_TOOLS)
	@cd ${WRKSRC}; tar cf - Tools | \
		(cd ${PREFIX}/lib/${PYTHON_VERSION}; tar xf -)
.endif

.include <bsd.port.post.mk>
