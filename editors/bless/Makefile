# New ports collection makefile for:	bless
# Date created:				24 October 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bless
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/bless/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	A high quality, full featured hex editor

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_X_PREFIX=   yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

DOCS=		AUTHORS Changelog NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|g' \
		${WRKSRC}/Makefile

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
