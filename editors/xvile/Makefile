# New ports collection makefile for:    xvile
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $FreeBSD$
#

PORTNAME=	xvile
PORTVERSION=	9.1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.phred.org/pub/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
DISTNAME=	vile-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gj@freebsd.org

USE_XLIB=	yes
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-screen=${SCREEN_TYPE} ${WITH_PERL}
MAN1=		xvile.1

pre-configure:
.if ! defined(USE_MENUS)
	@${ECHO_MSG} "To use xvile with menus, set the environment variable USE_MENUS"
.endif
.if ! defined(USE_PERL)
	@${ECHO_MSG} "To use xvile with PERL, set the environment variable USE_PERL"
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
.if defined(USE_PERL)
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/vile
.endif
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/vile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.mk>
