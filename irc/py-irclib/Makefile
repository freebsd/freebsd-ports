# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	irclib
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	irc python
MASTER_SITES=	SF/python-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-irclib-${PORTVERSION}

MAINTAINER=	william88@gmail.com
COMMENT=	IRC protocol client library for Python

USE_PYTHON=	-2.7
USE_ZIP=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	python-irclib
PYDISTUTILS_NOEGGINFO=yes

# TODO: irclib have some weird install script bundled and use of
#       USE_PYDISTUTILS=easy_install would break it
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}hgtools>0:${PORTSDIR}/devel/py-hgtools

PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

EXAMPLEFILES=	irccat irccat2 servermap testbot.py \
		dccreceive dccsend
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLEFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/${file} ${EXAMPLESDIR}/
.endfor
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/${PYDISTUTILS_EGGINFO} -type f -exec ${CHMOD} 644 {} +;
.endif

.include <bsd.port.mk>
