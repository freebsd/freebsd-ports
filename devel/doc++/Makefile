# New ports collection makefile for:	DOC++
# Date created:		20 Dec 1998
# Whom:			Ruslan@Shevchenko.Kiev.UA
# Version required:	3.2
#
# $Id$
#

DISTNAME=	docxxsrc
PKGNAME=	doc++-3.2
CATEGORIES=	devel
MASTER_SITES=	http://www.zib.de/Visual/software/doc++/

MAINTAINER=	Ruslan@Shevchenko.Kiev.UA

RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX \
		gs:${PORTSDIR}/print/ghostscript5 \
		anytopnm:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/src
USE_GMAKE=	yes

do-build:
	(cd ${WRKSRC}; gmake ${MAKE_ENV} all CXX=gcc LD=gcc LDFLAGS=-lstdc++ )

do-install:
	for i in ${WRKSRC}/bin/`uname -s`/*; do \
	  ${INSTALL_PROGRAM} $$i ${PREFIX}/bin ; \
	done

.include <bsd.port.mk>
