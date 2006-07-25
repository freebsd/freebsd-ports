# New ports collection makefile for:	DrScheme
# Date created:		21 Jun 2001
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drscheme
PORTVERSION=	351
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

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	An interactive, integrated, graphical Scheme programming environment

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-shared --x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib --enable-lt=${LIBTOOL}

WRKSRC=		${WRKDIR}/plt/src
USE_LDCONFIG=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	libtool:15:env

MAN1=		drscheme.1 help-desk.1 mred.1 mzscheme.1 tex2page.1

OPTIONS=	CAIRO "use Cairo graphics" off \
		MMM "use 3m garbage collection" off

ONLY_FOR_ARCHS=	i386

PLTPATCHES=	# none yet for this version

.include <bsd.port.pre.mk>

.if defined(WITH_CAIRO)
CONFIGURE_ARGS+=	--enable-cairo --enable-pthread
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
.else
CONFIGURE_ARGS+=	--disable-cairo
.endif

.if defined(WITH_MMM)
ALL_TARGET=		3m
INSTALL_TARGET+=	install-3m
PLIST_SUB+=		MMM=""
.else
PLIST_SUB+=		MMM="@comment "
.endif

.include <bsd.port.post.mk>
