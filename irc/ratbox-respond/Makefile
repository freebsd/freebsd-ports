# New ports collection makefile for:	ratbox-respond
# Date Created:				2006-04-29
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	ratbox-respond
PORTVERSION=	1.0
CATEGORIES=	irc sysutils
MASTER_SITES=	ftp://ftp.ircd-ratbox.org/pub/ircd-ratbox/${PORTNAME}/		\
		ftp://ftp.demon.co.uk/pub/mirrors/ircd-ratbox/${PORTNAME}/	\
		http://respond.ircd-ratbox.org/download/			\
		ftp://ftp.parodius.com/pub/ircd-ratbox/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shaun@inerd.com
COMMENT=	Client-side implementation of the challenge oper system in ircd-ratbox

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

EXTDIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${EXTDIR}/${PORTNAME}

SUB_FILES=	pkg-message

PORTDOCS=	challenge.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${EXTDIR}/makekeypair ${PREFIX}/bin

	@${MKDIR} ${EXAMPLESDIR}/client-scripts
	${INSTALL_DATA} ${EXTDIR}/client-scripts/* ${EXAMPLESDIR}/client-scripts

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${EXTDIR} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
