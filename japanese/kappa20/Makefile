# New ports collection makefile for:	kappafont
# Version required:	0.2
# Date created:		30 Sep 1997
# Whom: Kawaguti Ginga <ginga@amalthea.phys.s.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1998/04/24 05:37:15 asami Exp $
#

DISTNAME=	Kappa20-0.2
PKGNAME=	ja-kappa20-0.2
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.st.ryukoku.ac.jp/pub/X11/fonts/ \
		ftp://ftp.win.or.jp/pub/doc-sources/fj.sources/1997/aug/

MAINTAINER=	ginga@amalthea.phys.s.u-tokyo.ac.jp

USE_X_PREFIX=	yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/kappa20
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/kappa20/
.endif

.include <bsd.port.mk>
