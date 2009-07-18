# New ports collection Makefile for:    DrScheme
# Date created:         21 Jun 2001
# Whom:                 Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plt-scheme
PORTVERSION=	4.1.4
PORTREVISION=	2
CATEGORIES=	lang scheme
MASTER_SITES=	http://download.plt-scheme.org/bundles/${PORTVERSION}/plt/\
		http://plt.cs.uchicago.edu/bundles/${PORTVERSION}/plt/\
		http://www.cs.utah.edu/plt/download/${PORTVERSION}/plt/\
		http://mirror.informatik.uni-tuebingen.de/mirror/plt/${PORTVERSION}/plt/\
		ftp://infogroep.be/pub/plt/bundles/${PORTVERSION}/plt/\
		http://gd.tuwien.ac.at/languages/scheme/plt/${PORTVERSION}/plt/
DISTFILES=	plt-${PORTVERSION}-src-unix.tgz ${PLTPATCHES}
DIST_SUBDIR=	plt-scheme/${PORTVERSION}
EXTRACT_ONLY=	plt-${PORTVERSION}-src-unix.tgz

MAINTAINER=	areilly@bigpond.net.au
COMMENT=	An interactive, integrated, graphical Scheme programming environment

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo	\
		jpeg.10:${PORTSDIR}/graphics/jpeg	\
		png.5:${PORTSDIR}/graphics/png

USE_XORG=	xft x11 xrender xaw
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-shared --enable-xft --enable-gl \
		--enable-xrender --enable-cairo --with-x --enable-pthread \
		--enable-lt=${LIBTOOL} \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		CPPFLAGS="${CPPFLAGS}"

# Force the "configure" script to look in $LOCALBASE for -lpng and -ljpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/plt-${PORTVERSION}/src/build
USE_ICONV=	yes
USE_GL=		yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15:env

# no man files in this version: run plt-help for helpdesk
MAN1=	drscheme.1 mred.1 mzc.1 mzscheme.1 \
	plt-help.1 setup-plt.1 tex2page.1

#CGC is deprecated now
# OPTIONS=      CGC "With CGC garbage collector" off

ONLY_FOR_ARCHS=	i386 amd64

PLIST_SUB+=	ARCH=${ARCH}

PLTPATCHES=	# none yet for this version

CONFLICTS=	lang/drscheme

.include <bsd.port.pre.mk>

#.if defined(WITH_CGC)
#ALL_TARGET=            both
#INSTALL_TARGET=                install-both
#PLIST_SUB+=            CGC=""
#.else
#PLIST_SUB+=            CGC="@comment "
#.endif

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

pre-patch:
	${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
