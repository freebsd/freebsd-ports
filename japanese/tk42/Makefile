# New ports collection makefile for:	tk4.2p2JP
# Date created:		
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	4.2
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl7_6/
DISTNAME=	${PORTNAME}${PORTVERSION}p2

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	${PORTNAME}${VERSION}-patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp
COMMENT=	Japanized TK (Tcl Tool Kit)

LIB_DEPENDS=	tcl76jp.1:${PORTSDIR}/japanese/tcl76

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
USE_AUTOCONF_VER=	213
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} -E ${PATCH_DIST_STRIP}
PATCH_ARGS=		-d ${WRKDIR}/${DISTNAME} -E ${PATCH_STRIP}
.else
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
PATCH_ARGS=		-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_STRIP}
.endif

VERSION=	${PORTVERSION}jp

NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME}${PORTVERSION} ${WRKDIR}/${DISTNAME}

post-configure:
	@${ECHO} "We will NOT only make shared library, but also static one."
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} VERSION=${VERSION} && ${RM} -f *.o

pre-install:
	${MKDIR} ${PREFIX}/lib/tk${VERSION}

post-install:
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} VERSION=${VERSION} install
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libtk42jp.so.1.0 ${PREFIX}/lib/libtk42jp.so
.endif
	@${ECHO_MSG} "**********"
	@${ECHO_MSG} "IMPORTANT:"
	@${ECHO_MSG} "**********"
	@${ECHO_MSG} "We've installed:"
	@${ECHO_MSG} "tkConfig.sh in $(PREFIX)/lib/tk$(VERSION)/tkConfig.sh"
	@${ECHO_MSG} "tk.h        in $(PREFIX)/include/tk$(VERSION)/tk.h"
	@${ECHO_MSG} "These are NOT the default place, but good place to avoid"
	@${ECHO_MSG} "conflicting with another version of Tcl/Tks."

test:
	cd ${WRKSRC}; ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} test

install-man:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} install-man

.include <bsd.port.post.mk>
