# Created by: Bas Kruit <baskruit@bsltwr.dhis.org>
# $FreeBSD$

PORTNAME=	dhisd
PORTVERSION=	5.5
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/ \
		LOCAL/meta

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	DHIS server for dynamic updates on the server using specific engines

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libgmp.so:math/gmp

USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	USER="${USERS}" GROUP="${GROUPS}"
PLIST_SUB=	USER="${USERS}" GROUP="${GROUPS}"

USERS=		dhis
GROUPS=		dhis

DOCS=	CONTRIBUTORS INSTALL README

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}/var/run/dhis ${STAGEDIR}/var/log/dhis
	${INSTALL_DATA} ${WRKSRC}/dhisd.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/dhis.db.sample ${STAGEDIR}${PREFIX}/etc/dhisd.db.sample
	${INSTALL_PROGRAM} ${WRKSRC}/dhisd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/dhisgenkeys ${STAGEDIR}${PREFIX}/sbin

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhisd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhisgenkeys

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
