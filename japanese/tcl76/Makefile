# New ports collection makefile for:	tcl7.6jp
# Date created:		11 March 1997
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	tcl
PORTVERSION=	7.6
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl7_6/
DISTNAME=	${PORTNAME}${PORTVERSION}p2

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	${PORTNAME}${PORTVERSION}jp-patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp
COMMENT=	Japanized Tcl (Tool Command Language)

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
USE_AUTOCONF_VER=	213
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}
PKGINSTALL=	${PORTSDIR}/lang/tcl82/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl82/pkg-deinstall.tclsh

VERSION=	${PORTVERSION}jp

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME}${PORTVERSION} ${WRKDIR}/${DISTNAME}

post-configure:
	@${ECHO} "We will NOT only make shared library, but also static one."
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   VERSION=${VERSION} OSVERSION=${OSVERSION} && ${RM} *.o

pre-install:
	${MKDIR} ${PREFIX}/lib/tcl${VERSION}
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} VERSION=${VERSION} install

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libtcl76jp.so.1.0 ${PREFIX}/lib/libtcl76jp.so
.endif
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} test

install-man:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} install-man

.include <bsd.port.post.mk>
