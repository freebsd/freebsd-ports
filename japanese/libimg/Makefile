# New ports collection makefile for:	img
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	libimg
PORTVERSION=	1.2b2
CATEGORIES=	japanese graphics tk80
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/packages-8.0/graphics/Img/1.2/ \
		http://www.aaa-int.or.jp/~jfactory/TkStep/dist/
DISTNAME=	img${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced Tk adding support for many other Image formats

FORBIDDEN=	http://vuxml.FreeBSD.org/pkg-ja-libimg.html
EXPIRATION_DATE=2005-08-30

BUILD_DEPENDS=	${LOCALBASE}/lib/tcl8.0jp/tclIndex:${PORTSDIR}/japanese/tcl80 \
		${LOCALBASE}/lib/tk8.0jp/tk.tcl:${PORTSDIR}/japanese/tk80

USE_AUTOCONF_VER=	213
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl${TCLVERSION}jp \
		--with-tk=${PREFIX}/lib/tk${TKVERSION}jp \
		--disable-stubs
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/Img1.2

TCLVERSION=	8.0
TKVERSION=	8.0
PORTDOCDIR=	${PREFIX}/share/doc/img

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTDOCDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ANNOUNCE README changes ${PORTDOCDIR})
.endif
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libimg12.so.1.0 ${PREFIX}/lib/Img1.2/libimg12.so
.else
	${LN} -sf libimg12.so.1 ${PREFIX}/lib/Img1.2/libimg12.so
.endif

.include <bsd.port.post.mk>
