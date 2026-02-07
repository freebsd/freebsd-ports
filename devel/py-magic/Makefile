PORTNAME=	magic
PORTVERSION=	5.46
CATEGORIES=	devel python
MASTER_SITES=	https://astron.com/pub/file/ \
		ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.gw.com/mirrors/pub/unix/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/ \
		https://www.mirrorservice.org/sites/distfiles.macports.org/file/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	file-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python module for determining file type
WWW=		https://www.darwinsys.com/file/

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

# both install module as magic.py
CONFLICTS=	${PYTHON_PKGNAMEPREFIX}python-magic

WRKSRC=	${WRKDIR}/file-${PORTVERSION}/python

.include <bsd.port.mk>
