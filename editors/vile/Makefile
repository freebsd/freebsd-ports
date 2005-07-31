# New ports collection makefile for:    vile
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $FreeBSD$
#

PORTNAME=	vile
PORTVERSION=	9.5
CATEGORIES=	editors
MASTER_SITES=	ftp://dickey.his.com/vile/ \
		ftp://invisible-island.net/vile/ \
		ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=	.tgz

PATCH_SITES=    ${MASTER_SITES:S,vile/,vile/patches/,g}

MAINTAINER=	gj@FreeBSD.org
COMMENT=	VI Like Emacs.  a vi "workalike", with many additional features

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
USE_PERL5=	yes
MAN1=		vile.1

.if defined(WITH_ALL)
WITH_FILTERS=1
WITH_PERL=1
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+= --with-perl
PLIST=		${PKGDIR}/pkg-plist.perl
.endif

.if defined(WITH_FILTERS)
CONFIGURE_ARGS+= --with-loadable-filters
PLIST=		${PKGDIR}/pkg-plist.filt
.endif

.if defined(WITH_PERL) && defined(WITH_FILTERS)
PLIST=		${PKGDIR}/pkg-plist.perl+filt
.endif

pre-configure:
.if ! defined(WITH_PERL)
	@${ECHO_MSG} "Define WITH_PERL if you want to make a vile which includes"
	@${ECHO_MSG} "PERL functionality"
.endif
.if ! defined(WITH_FILTERS)
	@${ECHO_MSG} "Define WITH_FILTERS if you want to make a vile which will"
	@${ECHO_MSG} "dynamically load filters as needed."
.endif

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${PREFIX}/share/doc/vile ]; then ${MKDIR} ${PREFIX}/share/doc/vile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/vile
.endif
	@if ! [ -d ${PREFIX}/share/vile/macros ]; then ${MKDIR} ${PREFIX}/share/vile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/vile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/vile/macros
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/vile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.mk>
