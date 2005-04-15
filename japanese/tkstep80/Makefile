# New ports collection makefile for:	TkStep
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	tkstep
PORTVERSION=	8.0.5
CATEGORIES=	japanese tk80
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	tcl8_0
DISTNAME=	tk${PORTVERSION}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/ \
		http://www.aaa-int.or.jp/~jfactory/Factory/TkStep/dist/
PATCHFILES=	tk${PORTVERSION}jp1.6.patch.gz 2Step-${PORTVERSION}pl1-patch.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Tk toolkit with a NeXTSTEP look and more

LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80

USE_REINPLACE=	yes
USE_XLIB=	yes
USE_XPM=	yes
USE_AUTOCONF_VER=	213
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gcc --enable-shared --enable-step \
		--with-tcl=${PREFIX}/lib/tcl${TCLVERSION}jp \
		--enable-dnd --enable-xpm
WRKSRC=		${TOPDIR}/unix
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=-d ${TOPDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=-d ${TOPDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
PKGINSTALL=	${PORTSDIR}/x11-toolkits/tk82/pkg-install.wish
PKGDEINSTALL=	${PORTSDIR}/x11-toolkits/tk82/pkg-deinstall.wish
INSTALLS_SHLIB=	yes

TCLVERSION=	8.0
TOPDIR=		${WRKDIR}/${DISTNAME}
PORTDOCDIR=	${PREFIX}/share/doc/tkstep${TCLVERSION}jp

post-patch:
	@${REINPLACE_CMD} -e '/xpg4/d' ${WRKSRC}/configure.in

.include <bsd.port.pre.mk>

pre-install:
	cd ${TOPDIR}/library/demos.jp && ${RM} -f *.orig

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}
	cd ${TOPDIR}; \
	${INSTALL_DATA} README.TkStep ${PORTDOCDIR}
	cd ${TOPDIR}/tkstep; \
	${INSTALL_DATA} NOTES README.TkDND README.step ${PORTDOCDIR}
	cd ${TOPDIR}/tkstepjp; \
	${INSTALL_DATA} changes.TkSTEPjp ${PORTDOCDIR}
.endif
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.post.mk>
