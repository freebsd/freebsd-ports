# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	puredb
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://pureftpd.sourceforge.net/puredb/
DISTNAME=	pure-db-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of libraries for creating and reading constant databases

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS FORMAT_DESCR NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
