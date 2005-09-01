# New ports collection makefile for:	p5-qdbm
# Date created:		2005-09-01
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	p5-

COMMENT=	Perl API for QDBM

SLAVEPORT=	perl
USE_PERL5=	yes

MASTERDIR=	${.CURDIR}/../../databases/qdbm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/perl
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
