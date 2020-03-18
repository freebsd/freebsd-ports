# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	recutils
PORTVERSION=	1.8
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	zeus@ibs.dn.ua
COMMENT=	Tools and libraries to access human-editable, plain text databases

LICENSE=	GPLv3+

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USES=		charsetfix libtool makeinfo pkgconfig readline
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		rec-mode recutils
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS CURL GCRYPT MDB NLS
OPTIONS_DEFAULT=	GCRYPT
OPTIONS_SUB=	yes

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENV_OFF=	ac_cv_lib_curl_curl_global_init=no

GCRYPT_DESC=	Encryption support via GNU crypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_CONFIGURE_OFF=	--disable-encryption

MDB_DESC=	MS Access database (.mdb) support
MDB_LIB_DEPENDS=	libmdb.so:databases/mdbtools
MDB_CONFIGURE_ENV_OFF=	ac_cv_lib_mdb_mdb_init=no

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/*.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
