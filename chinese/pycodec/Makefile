# New ports collection makefile for:	zh-pycodec
# Date created:		24 June 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	1.2.0
CATEGORIES=	chinese python converters
MASTER_SITES=	http://www3.kr.freebsd.org/~perky/distfiles/ \
		http://fallin.lv/distfiles/ \
		#ftp://python-codecs.sourceforge.net/pub/python-codecs/
DISTNAME=	ChineseCodecs${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_SUB+=	PYTHON_CODECDIR=${PYCODEC_DIR:S,^${LOCALBASE}/,,g}
PYCODEC_DIR=	${PYTHON_LIBDIR}/encodings
PYDIST_SETUP=	cd ${WRKSRC}/Python && ${PYTHON_CMD} setup.py

do-install:
	${PYDIST_SETUP} install --install-lib="${PYCODEC_DIR}"

.include <bsd.port.mk>
