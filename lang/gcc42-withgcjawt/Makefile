# ex:ts=8
# Ports collection makefile for:	gcc with gcj+AWT
# Date created:				17 April 2006
# Whom:					Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-withgcjawt

MAINTAINER=	maho@FreeBSD.org

DESCR=	${.CURDIR}/pkg-descr

WITH_JAVA_AWT=	yes

.if ${OSVERSION} >= 600105
BROKEN=	Does not compile on FreeBSD >= 6.1
.endif

MASTERDIR=	${.CURDIR}/../../lang/gcc41
.include "${MASTERDIR}/Makefile"
