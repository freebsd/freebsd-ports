PORTNAME=	fatsort
PORTVERSION=	1.7.1.683
CATEGORIES=	filesystems
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	FATSort sorts directory structures of FAT file systems
WWW=		https://sourceforge.net/projects/fatsort

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	gmake tar:xz

MAKE_ENV=	MANDIR=${PREFIX}/share/man/man1 \
		INSTALL_FLAGS="-m 0555 -p"

PLIST_FILES=	sbin/fatsort share/man/man1/fatsort.1.gz

.include <bsd.port.mk>
