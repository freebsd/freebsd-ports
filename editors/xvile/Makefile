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
MAN1=		xvile.1

pre-configure:
.if ! defined(WITH_MENUS)
	@${ECHO_MSG} "To use xvile with menus, set the environment variable WITH_MENUS"
.endif
.if ! defined(WITH_PERL)
	@${ECHO_MSG} "To use xvile with PERL, set the environment variable WITH_PERL"
.endif

.if defined(WITH_MENUS)
CONFIGURE_ARGS= --with-screen=Xaw
.else
CONFIGURE_ARGS= --with-screen=x11
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+= --with-perl
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
.if defined(WITH_PERL)
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/vile
.endif
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/vile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.mk>
