# ex:ts=8
# Ports collection makefile for:  xwpe
# Version required:     	  1.6.2
# Date created:			  Fri Jan 24, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.5 1998/05/09 18:52:33 obrien Exp $
#

DISTNAME=	xwpe-1.5.9a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.rpi.edu/~payned/xwpe/ \
		ftp://identical.stu.rpi.edu/pub/linux/xwpe/
MASTER_SITE_SUBDIR=	apps/editors/X
EXTRACT_SUFX=	.tgz

MAINTAINER=     obrien@FreeBSD.org

# LD_LIBRARY_PATH is to deal with a braindead libX11.a search in configure
# (once again author assumes too many Linux'isms)
# it is not exptected to be set at runtime.
MAKE_ENV=	LD_LIBRARY_PATH="${X11BASE}/lib"
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LD_LIBRARY_PATH="${X11BASE}/lib"
USE_GMAKE=	yes
ALL_TARGET=
MAN1=		xwpe.1

post-install:
	@strip ${PREFIX}/bin/xwpe
	@(cd ${PREFIX}/man/man1 ; \
	for mp in xwe.1 wpe.1 we.1 ; \
		do ${RM} -f $$mp ; ln -sf xwpe.1.gz $$mp.gz ; done )

.include <bsd.port.mk>
