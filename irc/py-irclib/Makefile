# New ports collection makefile for:	py-irclib
# Date created:				25 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	irclib
PORTVERSION=	0.3.4
CATEGORIES=	irc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-irclib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-irclib-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes

PLIST_SUB+=	PYTHON_SITELIBDIR=lib/${PYTHON_VERSION}/site-packages \
		EXAMPLESDIR=${EXAMPLESDIR:S,^${PREFIX}/,,g}
EXAMPLEFILES=	ircbot.py irccat irccat2 servermap testbot.py

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/irclib.py* ${PREFIX}/lib/${PYTHON_VERSION}/site-packages/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
.for file in ${EXAMPLEFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
