# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.1.3
PORTREVISION=	2
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE} \
		http://SunSITE.Informatik.RWTH-Aachen.DE/python/ftp/python/${PORTVERSION}/
MASTER_SITE_SUBDIR=	python
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER?=	alane@FreeBSD.org

DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fpectl
CONFIGURE_ENV=	OPT="${CFLAGS}"
INSTALL_TARGET=	altinstall
MAN1=		${PYTHON_VERSION}.1

USE_PYTHON=	yes
PYTHON_VERSION=	python2.1
PYTHON_NO_DEPENDS=	yes

#
# If you don't want to use Python's thread module, you need to set
# WITHOUT_THREADS.
#
LIBC_R!=	/sbin/ldconfig -r | grep c_r || true
.if (${LIBC_R} != "") && !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--with-threads
CFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--without-threads
.endif

DEMODIR=	${PREFIX}/share/examples/${PYTHON_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
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
	${MKDIR} ${PYTHONPREFIX_LIBDIR}/${platform}
.for file in FCNTL.py IN.py regen
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/${file} \
		${PYTHONPREFIX_LIBDIR}/${platform}/
.endfor
.endfor

post-install:
	@${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Misc/python.man \
		${MANPREFIX}/man/man1/${PYTHON_VERSION}.1
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}; tar -c --exclude='*CVS*' -f - Tools | \
		(cd ${PYTHONPREFIX_LIBDIR}; tar xf -)
	@${MKDIR} ${DEMODIR}
	@cd ${WRKSRC}/Demo; tar -c --exclude='*CVS*' -f - * | \
		(cd ${DEMODIR}; tar xf -)
.endif

.if ${ARCH} == i386
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif

.include <bsd.port.post.mk>
