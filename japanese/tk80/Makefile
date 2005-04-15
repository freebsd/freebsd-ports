# New ports collection makefile for:	ja-tk8.0
# Date created:		26 Dec 1997
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	8.0.5
PORTREVISION=	2
CATEGORIES=	japanese x11-toolkits tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	${PORTNAME}${PORTVERSION}jp1.7.patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp
COMMENT=	Graphical toolkit for Japanized TCL, version 8.0

LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80

VERSION=	${PORTVERSION:R}
TOPDIR=		${WRKDIR}/${DISTNAME}
WRKSRC=		${TOPDIR}/unix
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=-d ${TOPDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=-d ${TOPDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
USE_AUTOCONF_VER=	213
USE_XLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-shared --with-tcl=${PREFIX}/lib/tcl${VERSION}jp \
	--enable-xlibHack --enable-onTheSpot
RANLIB=		ranlib
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/xpg4/d' ${WRKSRC}/configure.in
.if !defined(NOPORTDOCS)
	@${CP} ${FILESDIR}/README.FreeBSD.in ${TOPDIR}/README.FreeBSD.JP.in
	@${SED} -e 's%AC_OUTPUT(Makefile tkConfig.sh)%AC_OUTPUT(Makefile tkConfig.sh ../README.FreeBSD.JP)%' \
	  < ${WRKSRC}/configure.in \
	  > ${WRKSRC}/configure.in.tmp
	@${MV} -f ${WRKSRC}/configure.in.tmp ${WRKSRC}/configure.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tk${VERSION}jp
	@(cd ${TOPDIR}; \
	  ${INSTALL_DATA} README changes README.FreeBSD.JP \
		README.JP changes.JP \
		Incompat80jp ${PREFIX}/share/doc/tk${VERSION}jp; \
	 )
.endif
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libtk80jp.so.1.5 ${PREFIX}/lib/libtk80jp.so
	${RANLIB} ${PREFIX}/lib/libtk80jp.so
.endif
	@${CAT}	${PKGMESSAGE}

test:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} test

install-man:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} install-man

.include <bsd.port.post.mk>
