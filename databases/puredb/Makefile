# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	puredb
PORTVERSION=	2.1
CATEGORIES=	databases
MASTER_SITES=	http://pureftpd.sourceforge.net/puredb/
DISTNAME=	pure-db-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of libraries for creating and reading constant databases

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

DOCS=		AUTHORS FORMAT_DESCR NEWS README

.if !defined(NOPORTDOCS)
NO_STAGE=	yes
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
