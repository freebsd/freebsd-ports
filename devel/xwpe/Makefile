# ex:ts=8
# Ports collection makefile for:  xwpe
# Version required:     	  1.6.2
# Date created:			  Fri Jan 24, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.3 1997/04/22 10:50:10 obrien Exp $
#

DISTNAME=	xwpe-1.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}  \
		ftp://ftp.uni-hannover.de/pub/mirror/linux-distrib/apps/editors/X/
MASTER_SITE_SUBDIR=	apps/editors/X
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www.rpi.edu/~payned/xwpe/
PATCHFILES=	xwpe-cosmetic.patch xwpe-grep.patch \
		xwpe-naming.patch xwpe-xchanges.patch

MAINTAINER=     obrien@NUXI.com

# LD_LIBRARY_PATH is to deal with a braindead libX11.a search in configure
# (once again author assumes too many Linux'isms)
# it is not exptected to be set at runtime.
MAKE_ENV+=	LD_LIBRARY_PATH="${X11BASE}/lib"
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LD_LIBRARY_PATH="${X11BASE}/lib"
USE_GMAKE=	yes
ALL_TARGET=
.if defined(GERMAN_LANG)
INSTALL_TARGET= install_german
.endif
MAN1=		xwpe.1

post-install:
	@strip ${PREFIX}/bin/xwpe
	@(cd ${PREFIX}/man/man1 ; \
	for mp in xwe.1 wpe.1 we.1 ; \
		do ${RM} -f $$mp ; ln -sf xwpe.1.gz $$mp.gz ; done )
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xwpe
.if defined(GERMAN_LANG)
	${INSTALL_DATA} ${WRKSRC}/xwpe_gr.doc ${PREFIX}/share/doc/xwpe/xwpe.doc
.else
	${INSTALL_DATA} ${WRKSRC}/xwpe_eng.doc ${PREFIX}/share/doc/xwpe/xwpe.doc
.endif
.endif

.include <bsd.port.mk>
