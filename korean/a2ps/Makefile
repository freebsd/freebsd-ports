# New ports collection makefile for:    ko-a2ps
# Date created:         30 Sep 2000
# Whom:                 cjh
#
# $FreeBSD$
#

PORTNAME=	a2ps
PORTVERSION=	20000314
CATEGORIES=	korean print
MASTER_SITES=	http://www.kr.FreeBSD.org/~hwang/misc/
DISTNAME=	a2ps-h
EXTRACT_SUFX=	.py
EXTRACT_ONLY=

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Simple a2ps wrapper for Korean text printing

PLIST_FILES=	bin/a2ps-h
# depends on a2ps-a4. a2ps has several variation, so if I should
# choose one, a2ps-a4 is good because A4-sized paper is default in Korea.
RUN_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-a4

USE_PYTHON=	YES
NO_WRKSUBDIR=	YES
# default Korean PS font
PSFONTKO=	Gulim-Medium-KSC-EUC-H

pre-patch:
	${CP} ${_DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	${SED}	-e "s;%%PYTHON_CMD%%;${PYTHON_CMD};g" \
		-e "s;%%PSFONTKO%%;${PSFONTKO};g" \
		${WRKDIR}/a2ps-h.py > ${WRKDIR}/a2ps-h

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps-h ${PREFIX}/bin

.include <bsd.port.mk>
