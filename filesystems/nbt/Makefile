PORTNAME=	nbt
DISTVERSION=	${REVISION_DATE}
CATEGORIES=	filesystems
MASTER_SITES=	SF/nbtfsutils
PKGNAMEPREFIX=	fusefs-
DISTNAME=	nbtfsutils-${REVISION_DATE}-${REVISION_HASH}-src

MAINTAINER=	whr@rivoreo.one
COMMENT=	Editing Named Binary Tag (NBT) as using a file system
WWW=		https://sourceforge.net/projects/nbtfsutils/

LICENSE=	BEERWARE MIT MPL20
LICENSE_COMB=	multi
LICENSE_NAME_BEERWARE=	"THE BEER-WARE LICENSE" (Revision 42)
LICENSE_TEXT_BEERWARE=	Lukas Niederbremer <webmaster@flippeh.de> and Clark Gaebel <cg.wowus.cg@gmail.com> \
			wrote this file. As long as you retain this notice you can do whatever you \
			want with this stuff. If we meet some day, and you think this stuff is worth \
			it, you can buy us a beer in return.
LICENSE_FILE_MPL20=	${WRKSRC}/MPL-2.0
LICENSE_PERMS_BEERWARE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fuse localbase:ldflags tar:bz2
USE_LDCONFIG=	yes

REVISION_DATE=	20250506
REVISION_HASH=	dbd559a

MAKE_ENV=	MANDIR=\${PREFIX}/share/man
INSTALL_TARGET=	install-commands install-dev
NO_WRKSUBDIR=	yes

do-build:
	@cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} libnbt.so && ${DO_MAKE_BUILD} all

post-install:
.for l in lib/libnbt.so.1 bin/nbtdump bin/regiondump sbin/mkfs.nbt sbin/mount.nbt
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${l}
.endfor

.include <bsd.port.mk>
