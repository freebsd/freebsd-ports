# Created by: taguchi@tohoku.iij.ad.jp
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.0.5
PORTREVISION=	5
CATEGORIES=	japanese x11-toolkits tk
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	tcl8_0
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	${PORTNAME}${PORTVERSION}jp1.7.patch.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical toolkit for Japanized TCL, version 8.0

LIB_DEPENDS=	libtcl80jp.so:${PORTSDIR}/japanese/tcl80

VERSION=	${PORTVERSION:R}
TOPDIR=		${WRKDIR}/${DISTNAME}
WRKSRC=		${TOPDIR}/unix
DOCSDIR=	${PREFIX}/share/doc/tk${VERSION}jp
PORTDOCS=	README changes README.FreeBSD.JP README.JP changes.JP \
		Incompat80jp
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=-d ${TOPDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=-d ${TOPDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
USE_AUTOTOOLS=	autoconf213
USE_XORG=	x11
CONFIGURE_ARGS=	--enable-shared --with-tcl=${PREFIX}/lib/tcl${VERSION}jp \
	--enable-xlibHack --enable-onTheSpot
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
RANLIB=		ranlib
USE_LDCONFIG=	yes

NO_STAGE=	yes
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
	@${MKDIR} ${DOCSDIR}
	@(cd ${TOPDIR}; \
	  ${INSTALL_DATA} README changes README.FreeBSD.JP \
		README.JP changes.JP \
		Incompat80jp ${DOCSDIR}; \
	 )
.endif
	@${CAT}	${PKGMESSAGE}

test:
	cd ${WRKSRC} && ${MAKE} test

install-man:
	cd ${WRKSRC} && ${MAKE} install-man

.include <bsd.port.post.mk>
