# New ports collection makefile for:    AbiWord
# Version required:     0.7.6
# Date created:         3 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	abi-${VERSION}
PKGNAME=	AbiWord-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/Version-${VERSION}/lf/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} expat-${VERSION}.tar.gz \
		unixfonts-${VERSION}.tar.gz wv-${VERSION}.tar.gz

MAINTAINER=	dburr@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		png.3:${PORTSDIR}/graphics/png
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

DIST_SUBDIR=	AbiWord

VERSION=	0.7.6
WRKSRC=		${WRKDIR}/abi-${VERSION}/src
USE_XLIB=	yes
USE_GMAKE=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}" GLIB_CONFIG="${GLIB_CONFIG}"
OSDISTDIR=	${OPSYS}_`uname -r`_${ARCH}_OBJ

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} != 310000
	@${CP} 	${WRKSRC}/config/platforms/freebsd.mk \
		${WRKSRC}/config/platforms/freebsd.mk.version
	@${SED} -e s,3.1-RELEASE,`uname -r`,g \
		-e s,-D_POSIX_SOURCE,,g \
		${WRKSRC}/config/platforms/freebsd.mk.version > \
		${WRKSRC}/config/platforms/freebsd.mk
.endif

pre-build:
	@(cd ${WRKDIR}/wv && ./configure)

do-install:
	@${MKDIR} ${PREFIX}/AbiSuite/bin
	@${MKDIR} ${PREFIX}/AbiSuite/docs
	@(cd ${WRKDIR}/abi-${VERSION}/docs; for DOCS in *; do \
		${INSTALL_DATA} $${DOCS} ${PREFIX}/AbiSuite/docs/ \
		;done)
	@(cd ${WRKDIR}/abi-${VERSION}/test/wp; for TEST in *; do \
		${INSTALL_DATA} $${TEST} ${PREFIX}/AbiSuite/docs/ \
		;done)
	@${INSTALL_PROGRAM} ${WRKSRC}/${OSDISTDIR}/bin/AbiWord_s \
		${PREFIX}/AbiSuite/bin/
	@${LN} -sf ${PREFIX}/AbiSuite/bin/AbiWord ${PREFIX}/bin/AbiWord
	@${CP}	${WRKDIR}/unixfonts/install.sh \
		${WRKDIR}/unixfonts/install.sh.orig
	@${SED} s,/usr/local,${PREFIX}, \
		${WRKDIR}/unixfonts/install.sh.orig > \
		${WRKDIR}/unixfonts/install.sh
	@(cd ${WRKDIR}/unixfonts; yes "" | ./install.sh)
	@${CAT} ${PKGDIR}/MESSAGE | ${SED} s,/usr/local,${PREFIX},
	@(${WRKSRC}/pkg/common/unix/scripts/makewrapper.sh \
		AbiWord ${PREFIX}/AbiSuite)

.include <bsd.port.post.mk>
