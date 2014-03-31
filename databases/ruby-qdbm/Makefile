# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

COMMENT=	Ruby API for QDBM

SLAVEPORT=	ruby

USE_RUBY=	yes
MASTERDIR=	${.CURDIR}/../../databases/qdbm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/ruby
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"
