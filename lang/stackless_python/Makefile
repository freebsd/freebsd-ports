# Ports collection makefile for:  stackless_python
# Date created:			  29 March 2001
# Whom:				  Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.2.1
PORTREVISION=	${CVSDATE}0
CATEGORIES=	lang python
MASTER_SITES=	#
PKGNAMEPREFIX=	stackless_

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	perky
PATCHFILES=	stackless-${CVSDATE}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	perky@FreeBSD.org

ONLY_FOR_ARCHS=	i386 powerpc
CVSDATE=	020701
MASTERDIR=	${.CURDIR}/../../lang/python

COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;
	@${RM} -rf ${WRKSRC}/Demo/extend

.include "${MASTERDIR}/Makefile"
