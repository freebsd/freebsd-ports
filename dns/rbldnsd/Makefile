PORTNAME=	rbldnsd
PORTVERSION=	0.998
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.corpit.ru/mjt/rbldnsd/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Small and fast DNS daemon especially for DNSBL zones
WWW=		https://www.corpit.ru/mjt/rbldnsd.html

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
USE_RC_SUBR=	rbldnsd
USERS=		rbldns
GROUPS=		${USERS}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/example ${STAGEDIR}${ETCDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/rbldnsd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/rbldnsd.8 ${STAGEDIR}${PREFIX}/share/man/man8

do-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES-0.81 ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
