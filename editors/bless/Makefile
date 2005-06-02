# New ports collection makefile for:	bless
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $Id: Makefile,v 1.3 2005/05/10 16:34:16 mezz7 Exp $
# $FreeBSD$
#

PORTNAME=	bless
PORTVERSION=	0.3.5
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/bless/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	A high quality, full featured hex editor

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomehack gnomeprefix gnometarget
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_REINPLACE=	yes
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

.include <bsd.port.mk>
