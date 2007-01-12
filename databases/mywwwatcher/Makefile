# New ports collection makefile for:   	mywwwatcher
# Date created:				10 January 2007
# Whom:					Petr Macek <pm@kostax.cz>
#
# $FreeBSD$
#

PORTNAME=	mywwwatcher
PORTVERSION=	3.0
CATEGORIES=	databases www
MASTER_SITES=	http://www.the.cz/mywwwatcher/files/
DISTNAME=	mywwwatcher-${PORTVERSION}

MAINTAINER=	pm@kostax.cz
COMMENT=	Simply web-based mysql client + tools (dump, import, scheme, ...)

WRKSRC=		${WRKDIR}/mywwwatcher

DEFAULT_PHP_VER=	4
USE_PHP=		pcre session mysql

NO_BUILD=	yes

PKGMESSAGE=	${PKGDIR}/pkg-message
PLIST_SUB+=	INSTALLDIR=${INSTALLDIR}

INSTALLDIR=	www/${PORTNAME}

do-install:
	@${MKDIR} ${PREFIX}/${INSTALLDIR}
	@${CP} -Rp ${WRKSRC}/* ${PREFIX}/${INSTALLDIR}
	@${CHMOD} 775 ${PREFIX}/${INSTALLDIR}/ini
	@${CHMOD} 775 ${PREFIX}/${INSTALLDIR}/query_archive
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
