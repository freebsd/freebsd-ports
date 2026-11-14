PORTNAME=	bobbin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2.20250917
CATEGORIES=	emulators
PORTREVISION=	1

MAINTAINER=	alexey@pentode.fi
COMMENT=	Terminal-driven Apple II-series emulator
WWW=		https://github.com/micahcowan/bobbin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	micahcowan
GH_TAGNAME=	e331ff2

GNU_CONFIGURE=	yes

# Apple ROM and disk images are shipped in the distribution tarball, but
# they are copyrighted and not redistributable, so they are never installed
# by the package.
MAKE_ARGS+=	dist_rom_DATA="" dist_cardrom_DATA="" dist_disk_DATA=""

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

DOCS_MAKE_ARGS_OFF=	dist_doc_DATA=""

.include <bsd.port.mk>
