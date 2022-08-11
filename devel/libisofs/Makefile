PORTNAME=	libisofs
PORTVERSION=	1.5.4
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libburnia ISO9660 filesystem creation library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libburn.so:devel/libburn

USES=		iconv libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	susp_* Tutorial zisofs_format.txt

OPTIONS_DEFINE=	DEBUG DOCS LIBACL LIBJTE XATTR ZLIB
OPTIONS_DEFAULT=LIBACL LIBJTE XATTR ZLIB

LIBACL_DESC=	Enable use of ACL functions
LIBJTE_DESC=	Jigdo file support
XATTR_DESC=	Extended file attribute support

DEBUG_CONFIGURE_ENABLE=		debug
LIBACL_CONFIGURE_ENABLE=	libacl
LIBJTE_CONFIGURE_ENABLE=	libjte
XATTR_CONFIGURE_ENABLE=		xattr
ZLIB_CONFIGURE_ENABLE=		zlib

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
