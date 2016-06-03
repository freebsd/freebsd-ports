# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	ldnsm
PORTVERSION=	0.2.1
CATEGORIES=	dns
MASTER_SITES=	http://vvelox.net/src/ldap/

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Manages LDAP enteries for the BIND9 SDB LDAP patch

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
USES=		perl5 tar:tgz
NO_BUILD=	yes

PLIST_FILES=	bin/ldnsm man/man1/ldnsm.1.gz man/man5/dotldnsm.5.gz

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	@${EXEC} cd ${WRKSRC} ; ${WRKSRC}/install ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
