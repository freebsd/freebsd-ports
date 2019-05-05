# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parallels-tools
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/bland

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Parallels Desktop Tools for FreeBSD

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		kmod tar:bzip2 uidfix

PLIST_FILES=	${KMODDIR}/if_pvmnet.ko

.include <bsd.port.mk>
