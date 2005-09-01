# New ports collection makefile for:	ruby-qdbm
# Date created:		2005-09-01
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

COMMENT=	Ruby API for QDBM

SLAVEPORT=	ruby

USE_RUBY=	yes
MASTERDIR=	${.CURDIR}/../../databases/qdbm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/ruby
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
