# New ports collection makefile for:	p5-nkf
# Date created:		23 Feb 2000
# Whom:			max
#
# $FreeBSD$
#

CATEGORIES=	japanese perl5
PKGNAMEPREFIX=	ja-p5-

COMMENT=	A perl extension module to use NKF

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//:S/./-/}/NKF.mod
PATCHDIR=	${.CURDIR}/files
MAN3=		NKF.3

MASTERDIR=	${.CURDIR}/../nkf

.include "${MASTERDIR}/Makefile"
