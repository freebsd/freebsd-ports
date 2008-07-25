# New ports collection makefile for:	bless
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.22 2006/11/01 02:49:57 tmclau02 Exp $
#

PORTNAME=	bless
PORTVERSION=	0.5.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/bless/

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	A high quality, full featured hex editor

USE_GNOME=	gnomehack gnomeprefix gnometarget gnomedocutils gtksharp20
USE_GMAKE=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|data tests|data|g' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/$$(PACKAGE_NAME)-$$(PACKAGE_VERSION)|${DOCSDIR}|g'
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|src doc|src|g' \
		${WRKSRC}/Makefile.in
.endif

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
