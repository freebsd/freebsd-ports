# New ports collection makefile for:	poslib
# Date created:		2003-08-03
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	poslib
PORTVERSION=	1.0
CATEGORIES=	devel dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	posadis

MAINTAINER=	sergei@kolobov.com
COMMENT=	Posadis C++ DNS library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS} -D_REENTRANT"
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

DOCS=		AUTHORS ChangeLog NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
