# New ports collection makefile for:	pimp
# Date created:				23 February 2000
# Whom:					rbt
#
# $FreeBSD$
#

PORTNAME=	pimp3
PORTVERSION=	0.5.7
CATEGORIES=	audio
MASTER_SITES=	http://pimp3.sourceforge.net/files/

MAINTAINER=	rbt@zort.on.ca

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

WRKSRC=		${WRKDIR}/pimp3

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/*.pyc ${PREFIX}/bin/

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Take a look at the README to see how to install"
	@${ECHO_MSG} "and configure an audio database, among other"
	@${ECHO_MSG} "details that should be known."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Location: ${WRKDIR}/pimp3/README"
	@${ECHO_MSG}

.include <bsd.port.mk>
