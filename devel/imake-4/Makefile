# New ports collection makefile for:    Imake
# Date created:         01 Mar 2000
# Whom:                 max
#
# $FreeBSD$
#

PORTNAME= 	imake
PORTVERSION= 	4.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
DISTFILES=	X400src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

MANUAL_PACKAGE_BUILD=	installs/removes files also in the XFree86 port

PREFIX?=	${X11BASE}
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc/config
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.if !defined(NO_INSTALL_MANPAGES)
MAN1=		imake.1 lndir.1 makedepend.1 makeg.1 makestrs.1 \
		mkdirhier.1 pswrap.1 revpath.1 xmkmf.1
MANCOMPRESSED=	yes
INSTALL_TARGET=	install install.man
.else
INSTALL_TARGET=	install
.endif
# Followings are configration variables for XFree86 Systems.
HasSecureRPC?=	YES
HasXdmAuth?=	YES
HasPam?=	YES
BuildPexExt?=	YES
BuildXinerama?=	YES
BuildXIE?=	YES
BuildAoutLibraries?=	NO
# End of XFree86 configrations
SCRIPTS_ENV+=	OSVERSION=${OSVERSION} \
		PREFIX=${PREFIX} \
		X11BASE=${X11BASE} \
		WRKDIR=${WRKDIR} \
		DISTDIR=${DISTDIR} \
		FILESDIR=${FILESDIR} \
		HasSecureRPC=${HasSecureRPC} \
		HasXdmAuth=${HasXdmAuth} \
		HasPam=${HasPam} \
		BuildPexExt=${BuildPexExt} \
		BuildXinerama=${BuildXinerama} \
		BuildXIE=${BuildXIE} \
		BuildAoutLibraries=${BuildAoutLibraries}

.include <bsd.port.mk>
