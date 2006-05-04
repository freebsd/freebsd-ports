# New ports collection makefile for:    Imake
# Date created:         01 Mar 2000
# Whom:                 max
#
# $FreeBSD$
#

PORTNAME=	imake
PORTVERSION=	4.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	XFree86-${PORTVERSION}-src-1.tgz \
		XFree86-${PORTVERSION}-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Imake and other utilities from XFree86

CONFLICTS=	imake-6*

PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
USE_PERL5=	yes
MAKE_ENV=	MAKEFLAGS="CC=${CC}"
SCRIPTS_ENV=	CC=${CC}

.ifdef USE_IMAKE
.error You have `USE_IMAKE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE=	is part of XFree86 and you have ${X_WINDOW_SYSTEM} set for X11\
	distribution. See The X Window System and Virtual Consoles chapter\
	of FAQ for more information
.endif

DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc/config
MAN1=		ccmakedep.1 \
		cleanlinks.1 \
		gccmakedep.1 \
		imake.1 \
		lndir.1 \
		makedepend.1 \
		makeg.1 \
		makestrs.1 \
		mergelib.1 \
		mkdirhier.1 \
		mkhtmlindex.1 \
		pswrap.1 \
		revpath.1 \
		rman.1 \
		xmkmf.1
MANCOMPRESSED=	yes
SCRIPTS_ENV+=	OSVERSION=${OSVERSION} \
		HasSecureRPC=${HasSecureRPC} \
		BuildAoutLibraries=${BuildAoutLibraries} \
		DebuggableLibraries=${DebuggableLibraries} \
		InstallXdmConfig=${InstallXdmConfig} \
		InstallXinitConfig=${InstallXinitConfig} \
		InstallAppDefFiles=${InstallAppDefFiles}
INSTALL_TARGET=	install install.man

HasSecureRPC?=		YES
BuildAoutLibraries?=	NO
DebuggableLibraries?=	NO
InstallXdmConfig?=	YES
InstallXinitConfig?=	YES
InstallAppDefFiles?=	YES

pre-configure:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/cf/FreeBSD.cf

.include <bsd.port.post.mk>
