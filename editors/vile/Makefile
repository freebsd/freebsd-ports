# New ports collection makefile for:    vile
# Version required:     8.0
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $Id: Makefile,v 1.15 1998/06/04 20:04:55 gj Exp $
#

DISTNAME=	vile-8.0
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://ftp.phred.org./pub/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gj@freebsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
MAN1=		vile.1

.if defined(USE_PERL)
CONFIGURE_ARGS=	--with-perl
PLIST=		${PKGDIR}/PLIST.perl
USE_PERL5=	yes
.endif

pre-configure:
.if ! defined(USE_PERL)
	@echo "Define USE_PERL if you want to make a vile which includes"
	@echo "PERL functionality"
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
