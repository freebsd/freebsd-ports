# Ports collection makefile for:  stackless_python
# Date created:			  29 March 2001
# Whom:				  Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	""	# python port will override this, but it's for portlint
PKGNAMEPREFIX=	stackless_

PATCH_SITES=	http://www3.kr.freebsd.org/~perky/distfiles/ \
		http://www2.freebsd-kr.org/~perky/distfiles/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/
PATCHFILES=	stackless-010223_1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	perky@python.or.kr

MASTERDIR=	${.CURDIR}/../../lang/python

# stackless python port infoes
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo

SETUP_LOCAL+=	../../../lang/${PKGNAMEPREFIX}${PORTNAME}/files/Setup.stackless  # relative from python port

.include "${MASTERDIR}/Makefile"
