# New ports collection makefile for:	pimp
# Date created:				23 February 2000
# Whom:					rbt@zort.on.ca
#
# $FreeBSD$
#

PORTNAME=	pimp3
PORTVERSION=	0.5.8
CATEGORIES=	audio
MASTER_SITES=	http://unixpages.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rate your mp3s for a randomized playlist you will actually like

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm

WRKSRC=		${WRKDIR}/pimp3

USE_REINPLACE=	yes
NO_BUILD=	yes
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e "s!/usr/bin/python!${LOCALBASE}/bin/python!" ${WRKSRC}/pimp3.py

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
