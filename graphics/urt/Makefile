# New ports collection makefile for:	urt
# Version required:	3.1b
# Date created:		Jan 5 1997
# Whom:			cfs@ing.puc.cl (original)
#
# $Id: Makefile,v 1.3 1997/06/06 05:31:56 asami Exp $
#

DISTNAME=	urt
PKGNAME=	urt-3.1b
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.utah.edu/pub/
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar urt-img.tar

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co

LIB_DEPENDS=	tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34
BUILD_DEPENDS=	${X11BASE}/lib/libpbm.a:${PORTSDIR}/graphics/netpbm

NO_WRKSUBDIR=   yes
EXTRACT_ONLY=	urt-3.1b.tar.Z

post-install:
		${MKDIR} ${PREFIX}/share/doc/urt
		cd ${PREFIX}/share/doc/urt; \
		  tar xf $(DISTDIR)/urt-doc.tar; \
		  cd doc; \
		  find -d . | cpio -dump ..; \
		  cd ..; \
		  rm -rf doc; \
		  tar xf $(DISTDIR)/urt-img.tar; \
		  chown -R root:wheel . ; \
		  find . -type d -exec chmod 775 '{}' \; ; \
		  find . -type f -exec chmod 664 '{}' \;

.include <bsd.port.mk>
