# New ports collection makefile for:    xvile
# Version required:     8.0
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $Id: Makefile,v 1.17 1998/11/28 00:44:33 asami Exp $
#

DISTNAME=	vile-8.0
PKGNAME=	xvile-8.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://ftp.phred.org./pub/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gj@freebsd.org

USE_XLIB=	yes
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-screen=${SCREEN_TYPE} ${WITH_PERL}
MAN1=		xvile.1

pre-configure:
.if ! defined(USE_MENUS)
	@echo "To use xvile with menus, set the environment variable USE_MENUS"
.endif
.if ! defined(USE_PERL)
	@echo "To use xvile with PERL, set the environment variable USE_PERL"
.endif

.if defined(USE_MENUS)
SCREEN_TYPE=	Xaw
.else
SCREEN_TYPE=	x11
.endif

.if defined(USE_PERL)
WITH_PERL=	--with-perl
PLIST=		${PKGDIR}/PLIST.perl
USE_PERL5=	yes
.endif

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${PREFIX}/share/doc/vile ]; then ${MKDIR} ${PREFIX}/share/doc/vile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/vile
.endif
	@if ! [ -d ${PREFIX}/share/vile/macros ]; then ${MKDIR} ${PREFIX}/share/vile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/vile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/vile/macros
	@echo "Look in ${PREFIX}/share/doc/vile for documentation."
	@echo "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.mk>
