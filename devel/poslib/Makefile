# New ports collection makefile for:	poslib
# Date created:		2003-08-03
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	poslib
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	devel dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	posadis

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Posadis C++ DNS library

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

DOCS=		AUTHORS ChangeLog NEWS README TODO
EXAMPLES=	examples/*.cpp

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
