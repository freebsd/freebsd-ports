# Ports collection makefile for:  stackless_python
# Date created:			  29 March 2001
# Whom:				  Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.0.1
CATEGORIES=	lang python
MASTER_SITES=	""
PKGNAMEPREFIX=	stackless_

PATCH_SITES=	http://www3.kr.freebsd.org/~perky/distfiles/ \
		http://pipiband.com/distfiles/
PATCHFILES=	stackless-010514.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	perky@fallin.lv

MASTERDIR=	${.CURDIR}/../../lang/python20

COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo

SETUP_LOCAL+=	../../../lang/${PKGNAMEPREFIX}${PORTNAME}/files/Setup.stackless

.include "${MASTERDIR}/Makefile"
