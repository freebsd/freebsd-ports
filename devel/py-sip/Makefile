# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	3.4
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=

MAINTAINER=	nbm@FreeBSD.org

LIB_DEPENDS=	sip.9:${PORTSDIR}/devel/sip

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${LN} -s ${LOCALBASE}/lib/libsip.so ${PYTHONPREFIX_SITELIBDIR}/libsip.so

.include <bsd.port.mk>
