# New ports collection makefile for:	pimp
# Date created:				23 February 2000
# Whom:					rbt@zort.on.ca
#
# $FreeBSD$
#

PORTNAME=	pimp3
PORTVERSION=	0.5.8
CATEGORIES=	audio
MASTER_SITES=	ftp://pimp3.sourceforge.net/pub/pimp3/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

BROKEN=		Requires gdbm support which is not built\
		by default by python

WRKSRC=		${WRKDIR}/pimp3

NO_BUILD=	yes
USE_PYTHON=	yes

post-patch:
	@${PERL} -pi -ne "s!/usr/bin/python!${LOCALBASE}/bin/python!;" ${WRKSRC}/pimp3.py

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
