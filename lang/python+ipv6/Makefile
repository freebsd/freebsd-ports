# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	lang python ipv6
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/
PKGNAMESUFFIX=	+ipv6
DISTFILES=	${PYTHON_DISTFILE}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	${PORTNAME}-${PORTVERSION:S/.//g}-v6-20000120.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org

DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fpectl
CONFIGURE_ENV=	OPT="${CFLAGS}"
INSTALL_TARGET=	install
PLIST=		${WRKDIR}/PLIST
MAN1=		python.1

USE_PYTHON=	yes
PYTHON_VERSION=	python1.5
PYTHON_NO_DEPENDS=	yes

#
# The standard setup file
#
SETUP_FILE=	Setup

#
# If you don't want to use Python's thread module, you need to set
# WITHOUT_THREADS. libc_r should be installed on nowadays' systems.
#
LIBC_R!=	/sbin/ldconfig -r | grep c_r || true
.if (${LIBC_R} == "") || defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--without-threads
.else
CONFIGURE_ARGS+=	--with-threads
CFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
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
# to a web tree checker, to a collectioln of simple scripts that are useful
# while extending or managing Python.
#
.if !defined(WITHOUT_TOOLS)
PLIST_TOOLS=	${PKGDIR}/pkg-plist.Tools
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

.if ${OSVERSION} >= 400014
PLIST_V6=	${PKGDIR}/pkg-plist.v6
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${OSVERSION} >= 500000 && ${OSVERSION} < 500005
CONFIGURE_ARGS+=	--with-libs='-lxpg4'
.endif
.if ${OSVERSION} < 400020
CONFIGURE_ARGS+=	--with-libs='-lxpg4'
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
	${MKDIR} ${PYTHON_LIBDIR}/${platform}
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/*                    \
		${PYTHON_LIBDIR}/${platform}/
.endfor
	@sort -r -o ${PLIST} ${PLIST_GMP} ${PLIST_TOOLS} ${PLIST_V6} ${PKGDIR}/pkg-plist

post-install:
	strip ${PREFIX}/bin/python
	@${MKDIR} ${PREFIX}/share/doc/python
	@${MKDIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/Misc/python-mode.el ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/Misc/COPYRIGHT ${PREFIX}/share/doc/python
	${INSTALL_DATA} ${WRKSRC}/README.v6 ${PREFIX}/share/doc/python
	@${MKDIR} ${PYTHON_SITELIBDIR}
.if !defined(WITHOUT_TOOLS)
	@cd ${WRKSRC}; tar cf - Tools | \
		(cd ${PYTHON_LIBDIR}; tar xf -)
.endif

.include <bsd.port.post.mk>
