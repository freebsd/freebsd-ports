# New ports collection makefile for:	TkStep
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	tkstep
PORTVERSION=	8.0.4
CATEGORIES=	japanese tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/
DISTNAME=	tk${PORTVERSION}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/ \
		http://www.aaa-int.or.jp/~jfactory/TkStep/dist/
PATCHFILES=	tk${PORTVERSION}jp1.3.patch.gz tk${PORTVERSION}-Stepnize.gz

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80

USE_XLIB=	yes
USE_AUTOCONF=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gcc --enable-shared --enable-step \
		--with-tcl=${PREFIX}/lib/tcl${TCLVERSION}jp \
		--enable-dnd
WRKSRC=		${TOPDIR}/unix
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=-d ${TOPDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=-d ${TOPDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
PKGINSTALL=	${PORTSDIR}/x11-toolkits/tk82/pkg/INSTALL.wish
PKGDEINSTALL=	${PORTSDIR}/x11-toolkits/tk82/pkg/DEINSTALL.wish

TCLVERSION=	8.0
TOPDIR=		${WRKDIR}/${DISTNAME}
PORTDOCDIR=	${PREFIX}/share/doc/tkstep${TCLVERSION}jp

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}
	cd ${TOPDIR}/doc.tkstep; \
	${INSTALL_DATA} INSTALL.TkSTEPjp NOTES README.TkDND README.TkSTEPjp \
		README.TkStep README.step changes.TkSTEPjp ${PORTDOCDIR}
.endif
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.post.mk>
