# New ports collection makefile for:    Imake
# Date created:         01 Mar 2000
# Whom:                 max
#
# $FreeBSD$
#

PORTNAME=	imake
PORTVERSION=	4.3.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	X430src-1.tgz X430src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Imake and other utilities from XFree86

PREFIX?=	${X11BASE}
USE_PERL5=	YES
USE_REINPLACE=	yes

.ifdef USE_IMAKE
.error You have `USE_IMAKE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LATEST_LINK=	imake4
.else
LATEST_LINK=	imake
.endif
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc/config
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
PATCH_DIST_ARGS=	--force -d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP} 2>/dev/null || true
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

post-install:
	@${MKHTMLINDEX} ${PREFIX}/lib/X11/doc/html

.include <bsd.port.post.mk>
