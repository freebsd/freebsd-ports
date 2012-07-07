# New ports collection makefile for:	ratbox-respond
# Date Created:				2006-04-29
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	ratbox-respond
PORTVERSION=	1.0
CATEGORIES=	irc sysutils
MASTER_SITES=	http://respond.ratbox.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client-side implementation of the challenge oper system in ircd-ratbox

CONFIGURE_WRKSRC=${WRKSRC}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/ratbox-respond bin/makekeypair

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/makekeypair ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} challenge.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/client-scripts
	${INSTALL_DATA} ${WRKSRC}/client-scripts/* ${EXAMPLESDIR}/client-scripts
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
