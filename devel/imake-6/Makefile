# New ports collection makefile for:    imake-6
# Date created:         18 Jun 2004
# Whom:                 anholt
#
# $FreeBSD$
#

PORTNAME=	imake
PORTVERSION=	6.7.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/ \
		${MASTER_SITE_XORG} \
MASTER_SITE_SUBDIR=	R6.7/tars
DISTFILES=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src3.tar.gz

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

NO_LATEST_LINK=	yes
DIST_SUBDIR=	xorg
WRKSRC=		${WRKDIR}/xc/config
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
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

post-install:
	@${MKHTMLINDEX} ${PREFIX}/lib/X11/doc/html

.include <bsd.port.post.mk>
