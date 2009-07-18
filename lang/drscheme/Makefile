# New ports collection makefile for:	DrScheme
# Date created:		21 Jun 2001
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drscheme
PORTVERSION=	370
PORTREVISION=	4
CATEGORIES=	lang scheme
MASTER_SITES=	http://download.plt-scheme.org/bundles/${PORTVERSION}/plt/ \
		http://www.cs.utah.edu/plt/download/${PORTVERSION}/plt/ \
		ftp://ftp.pasteur.fr/pub/computing/Scheme/plt-scheme/${PORTVERSION}/plt/ \
		ftp://archive.informatik.uni-tuebingen.de/unix/language/plt/${PORTVERSION}/plt/ \
		ftp://infogroep.be/pub/plt/bundles/${PORTVERSION}/plt/ \
		ftp://morpheus.wish.com.mx/pub/plt/${PORTVERSION}/plt/ \
		http://download.plt-scheme.org/patches/${PORTVERSION}/:PLT
DISTFILES=	plt-${PORTVERSION}-src-unix.tgz ${PLTPATCHES}
DIST_SUBDIR=	drscheme/${PORTVERSION}
EXTRACT_ONLY=	plt-${PORTVERSION}-src-unix.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive, integrated, graphical Scheme programming environment

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo	\
		jpeg.10:${PORTSDIR}/graphics/jpeg	\
		png.5:${PORTSDIR}/graphics/png

USE_XORG=	xft x11 xrender xaw
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-shared --enable-xft --enable-gl \
		--enable-xrender --enable-cairo --with-x --enable-pthread \
		--enable-lt=${LIBTOOL} \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		CPPFLAGS="${CPPFLAGS}"

# Force the "configure" script to look in $LOCALBASE for -lpng and -ljpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/plt-${PORTVERSION}/src
USE_ICONV=	yes
USE_GL=		yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15:env

MAN1=		drscheme.1 help-desk.1 mred.1 mzscheme.1 tex2page.1

OPTIONS=	CGC "With CGC garbage collector" off

ONLY_FOR_ARCHS=	i386 amd64

PLIST_SUB+=	ARCH=${ARCH}

PLTPATCHES=	# none yet for this version

.if defined(PACKAGE_BUILDING)
IGNORE=		signal 10 in mzscheme3m during build on pointyhat
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_CGC)
ALL_TARGET=		both
INSTALL_TARGET=		install-both
PLIST_SUB+=		CGC=""
.else
PLIST_SUB+=		CGC="@comment "
.endif

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

.include <bsd.port.post.mk>
