# New ports collection makefile for:	py-irclib
# Date created:				25 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	irclib
PORTVERSION=	0.3.1
CATEGORIES=	irc python
MASTER_SITES=	http://joel.rosdahl.net/hacks/ \
		http://www3.kr.freebsd.org/~perky/distfiles/ \
		http://www2.freebsd-kr.org/distfiles/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@python.or.kr

USE_PYTHON=	yes

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}
EXAMPLEFILES=	ircbot.py irccat irccat2 servermap testbot.py

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/irclib.py* ${PYTHON_SITELIBDIR}/
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
.for file in ${EXAMPLEFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/share/examples/${PORTNAME}/
.endfor
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/${PORTNAME}/

.include <bsd.port.mk>
