# New ports collection makefile for:    Imake
# Date created:         01 Mar 2000
# Whom:                 max
#
# $FreeBSD$
#

PORTNAME=	imake
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.6/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/3.3.6/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-3.3.6/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/3.3.6/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.6/source/
DISTNAME=	X336src-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	max@FreeBSD.org

MANUAL_PACKAGE_BUILD=	installs/removes files also in the XFree86 port

PREFIX=		${X11BASE}
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc/config
MAN1=		imake.1 lndir.1 makedepend.1 xmkmf.1 makestrs.1 \
		makeg.1 mkdirhier.1
MANCOMPRESSED=	yes
INSTALL_TARGET=	install install.man
MTREE_FILE=	/etc/mtree/BSD.x11.dist

do-configure:
	@${ECHO} > ${WRKSRC}/cf/host.def
	@(cd ${WRKDIR}/xc; \
	  ${MAKE} Makefile.boot ; \
	  ${MAKE} -f xmakefile SUBDIRS="include config" VerifyOS Makefiles includes)

.include <bsd.port.mk>
