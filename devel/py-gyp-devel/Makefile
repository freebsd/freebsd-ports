# New ports collection makefile for:	py-gyp
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gyp
PORTVERSION=	r832
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Generate Your Projects

RUN_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/grep:${PORTSDIR}/textproc/gnugrep

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.1

REPLACE_FILES=  ${WRKSRC}/pylib/gyp/generator/make.py

post-patch:
	@for FILE in ${REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

.include <bsd.port.mk>
