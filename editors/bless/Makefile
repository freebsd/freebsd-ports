# New ports collection makefile for:	bless
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.22 2006/11/01 02:49:57 tmclau02 Exp $
#

PORTNAME=	bless
PORTVERSION=	0.6.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/bless/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A high quality, full featured hex editor

USE_GNOME=	gnomehack gnomeprefix gnometarget gnomedocutils gtksharp20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
INSTALLS_OMF=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|tests$$||g' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/$$(PACKAGE_NAME)-$$(PACKAGE_VERSION)|${DOCSDIR}|g'
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|data doc|data|g' \
			  -e '/^install-data-local:/,/^$$/d' \
			  -e 's|install-data-local||' \
		${WRKSRC}/Makefile.in
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
