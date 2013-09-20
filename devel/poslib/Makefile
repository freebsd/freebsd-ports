# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	poslib
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	devel dns
MASTER_SITES=	SF/posadis/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Posadis C++ DNS library

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

DOCS=		AUTHORS ChangeLog NEWS README TODO
EXAMPLES=	examples/*.cpp

NO_STAGE=	yes
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
