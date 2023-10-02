PORTNAME=	parallels-tools
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/bland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallels Desktop Tools for FreeBSD
WWW=		https://www.parallels.com/products/desktop/

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		kmod tar:bzip2 uidfix

PLIST_FILES=	${KMODDIR}/if_pvmnet.ko

.include <bsd.port.mk>
