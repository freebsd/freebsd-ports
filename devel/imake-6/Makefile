# New ports collection makefile for:    imake-6
# Date created:         18 Jun 2004
# Whom:                 anholt
#
# $FreeBSD$
#

PORTNAME=	imake
PORTVERSION=	6.8.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R${PORTVERSION}/src
DISTFILES=	X11R${PORTVERSION}-src1.tar.gz \
		X11R${PORTVERSION}-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Imake and other utilities from X.Org

CONFLICTS=	imake-4*

PREFIX?=	${X11BASE}
USE_PERL5=	YES
USE_REINPLACE=	yes

.ifdef USE_IMAKE
.error You have `USE_IMAKE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

DIST_SUBDIR=	xorg
WRKSRC=		${WRKDIR}/xc/config
MTREE_FILE=	${PORTSDIR}/x11-servers/xorg-server/files/BSD.x11-xorg.dist
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
INSTALL_TARGET=	install install.man

pre-configure:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/cf/FreeBSD.cf

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=		is part of X.Org. For switching to X.Org, read UPDATING entry 20040723
.endif

.include <bsd.port.post.mk>
