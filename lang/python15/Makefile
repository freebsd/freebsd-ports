# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	1.5.2
PORTREVISION=	3
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
LATEST_LINK=	${PYTHON_VERSION:S/.//g}

USE_PYTHON=	yes
PYTHON_VERSION=	python1.5
PYTHON_NO_DEPENDS=	yes

#
# The standard setup file
#
SETUP_FILE=	Setup

#
# If you don't want to use Python's thread module, you need to set
# WITHOUT_THREADS.
#
.if !defined(NOLIBC_R) && !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--with-thread
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
# to a web tree checker, to a collection of simple scripts that are useful
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
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/*                    \
		${PYTHONPREFIX_LIBDIR}/${platform}
.endfor
	@${SORT} -r -o ${PLIST} ${PLIST_GMP} ${PLIST_TOOLS} ${PKGDIR}/pkg-plist

post-install:
	@${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Misc/python.man \
		${MANPREFIX}/man/man1/${PYTHON_VERSION}.1
	@${MKDIR} ${PREFIX}/share/doc/${PYTHON_VERSION}
	${INSTALL_DATA} ${WRKSRC}/Misc/COPYRIGHT ${PREFIX}/share/doc/${PYTHON_VERSION}
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
.if !defined(WITHOUT_TOOLS)
	@cd ${WRKSRC}; tar cf - Tools | (cd ${PYTHONPREFIX_LIBDIR}; tar xf -)
.endif

.include <bsd.port.post.mk>
