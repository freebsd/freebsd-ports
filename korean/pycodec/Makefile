# New ports collection makefile for:	ko-pycodec
# Date created:		29 April 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	1.4
CATEGORIES=	korean python converters
MASTER_SITES=	ftp://people.linuxkorea.co.kr/pub/Python/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/ \
		ftp://www3.kr.freebsd.org/pub/FreeBSD/ports/distfiles/
DISTNAME=	KoreanCodecs-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
PYTHON_CODECDIR=${PYTHON_LIBDIR}/encodings
PLIST_SUB+=	PYTHON_CODECDIR=${PYTHON_CODECDIR:S,^${LOCALBASE}/,,g}

# Since there's only one popular encoding in korea,
# this codec doesn't install into site-packages like ja-pycodec
# for using like unicode("KANADARA", "euc-kr")
do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/euc_kr.py* ${WRKSRC}/uhc.py* \
		${PYTHON_CODECDIR}/
	${MKDIR} ${PYTHON_CODECDIR}/korean
	${INSTALL_DATA} ${WRKSRC}/korean/* ${PYTHON_CODECDIR}/korean

.include <bsd.port.mk>
