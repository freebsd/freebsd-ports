# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	ratbox-respond
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	irc sysutils
MASTER_SITES=	http://respond.ratbox.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client-side implementation of the challenge oper system in ircd-ratbox

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

CONFIGURE_WRKSRC=${WRKSRC}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	challenge.txt
PORTEXAMPLES=	*
PLIST_FILES=	bin/ratbox-respond bin/makekeypair

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/makekeypair ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/challenge.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/client-scripts/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
