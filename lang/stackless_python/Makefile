# Ports collection makefile for:  stackless_python
# Date created:			  29 March 2001
# Whom:				  Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.2.3
PORTREVISION=	${CVSDATE}0
CATEGORIES=	lang python
MASTER_SITES=	#
PKGNAMEPREFIX=	stackless_

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
PATCH_SITE_SUBDIR=	perky
PATCHFILES=	stackless-${CVSDATE}.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python implementation that does not use the C stack

ONLY_FOR_ARCHS=	i386 powerpc
CVSDATE=	021026
MASTERDIR=	${.CURDIR}/../../lang/python

DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${WRKDIR}/pkg-plist
BROKEN=		"not ported to Python-2.2.3 yet"
DEPRECATED=	"Will be removed after April 7 if still broken"

#post-patch:
#	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;
#	@${RM} -rf ${WRKSRC}/Lib/test/output/test_atexit \
#			${WRKSRC}/Lib/test/output/test_minidom
#	@${ECHO} "lib/%%PYTHON_VERSION%%/lib-dynload/stackless.so" >${PLIST}
#	@${CAT} ${MASTERDIR}/pkg-plist >>${PLIST}

.include "${MASTERDIR}/Makefile"
