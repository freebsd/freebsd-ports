# New ports collection makefile for:    vile
# Version required:     8.2
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $FreeBSD$
#

DISTNAME=	vile-8.2
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://ftp.phred.org/pub/vile/ \
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
	@${ECHO_MSG} "Define USE_PERL if you want to make a vile which includes"
	@${ECHO_MSG} "PERL functionality"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${PREFIX}/share/doc/vile ]; then ${MKDIR} ${PREFIX}/share/doc/vile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/vile
.endif
	@if ! [ -d ${PREFIX}/share/vile/macros ]; then ${MKDIR} ${PREFIX}/share/vile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/vile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/vile/macros
.if defined(USE_PERL)
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/vile
.endif
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/vile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.mk>
