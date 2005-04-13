# New ports collection makefile for:	bless
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bless
PORTVERSION=	0.3.3
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/bless/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	A high quality, full featured hex editor

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|data tests|data|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/applications|(prefix)/share/gnome/applications|g ; \
		s|[(]datadir[)]/pixmaps|(prefix)/share/gnome/pixmaps|g' \
			${WRKSRC}/data/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|doc/$$(PACKAGE_NAME)-$$(PACKAGE_VERSION)|doc/$$(PACKAGE_NAME)|g'
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
