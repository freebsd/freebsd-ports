# New ports collection makefile for:    AbiWord
# Version required:     0.5.5
# Date created:         3 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	abi-0.5.5-src
PKGNAME=	AbiWord-0.5.5
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} expat.tar.gz \
		unixfonts-0.5.4.tar.gz

MAINTAINER=	dburr@FreeBSD.org

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		png.3:${PORTSDIR}/graphics/png
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

DIST_SUBDIR=	AbiWord

WRKSRC=		${WRKDIR}/abi-0.5.5/src
USE_XLIB=	YES
USE_GMAKE=	YES

# the build is placed in a directory name of the form
# FreeBSD_3.1-RELEASE_i386_OBJ.  This variable makes it
# a bit easier to type this whenever it's needed in the
# do-install target.
OSDISTDIR=	`uname -s`_`uname -r`_`uname -m`_OBJ

.include <bsd.port.pre.mk>

post-patch:
	@ cd ${WRKDIR} && ${LN} -sf abi-0.5.5 abi
.if ${OSVERSION} > 310000
	@${CP} 	${WRKSRC}/config/platforms/freebsd.mk \
		${WRKSRC}/config/platforms/freebsd.mk.version
	@${SED} -e s,3.1-RELEASE,`uname -r`,g \
		${WRKSRC}/config/platforms/freebsd.mk.version > \
		${WRKSRC}/config/platforms/freebsd.mk
.endif

do-install:
	${MKDIR} ${PREFIX}/AbiSuite/bin
	${MKDIR} ${PREFIX}/AbiSuite/lib
	( cd ${WRKDIR}/abi-0.5.5/dist/${OSDISTDIR}/bin ; for BIN in *; do ${INSTALL_PROGRAM} $${BIN} ${PREFIX}/AbiSuite/bin ; done )
	( cd ${WRKDIR}/abi-0.5.5/dist/${OSDISTDIR}/lib ; for LIB in *; do ${INSTALL_DATA} $${LIB} ${PREFIX}/AbiSuite/lib ; done )
	@${CP}	${WRKDIR}/unixfonts-0.5.4/install.sh \
		${WRKDIR}/unixfonts-0.5.4/install.sh.orig
	@${SED} s,/usr/local,${PREFIX}, \
		${WRKDIR}/unixfonts-0.5.4/install.sh.orig > \
		${WRKDIR}/unixfonts-0.5.4/install.sh
	( cd ${WRKDIR}/unixfonts-0.5.4 ; yes "" | bash ./install.sh )
	for BIN in ${PREFIX}/AbiSuite/bin/* ; do ${LN} -sf $${BIN} ${PREFIX}/bin ; done
	@${CAT} ${PKGDIR}/MESSAGE | ${SED} s,/usr/local,${PREFIX},

.include <bsd.port.post.mk>
