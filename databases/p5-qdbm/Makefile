# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	p5-

COMMENT=	Perl API for QDBM

SLAVEPORT=	perl
USES=		perl5

MASTERDIR=	${.CURDIR}/../../databases/qdbm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/perl
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr
PATCHDIR=	${.CURDIR}/files

MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
