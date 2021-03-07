# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	recutils
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Tools and libraries to access human-editable, plain text databases

LICENSE=	GPLv3+

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USES=		charsetfix libtool makeinfo pkgconfig readline
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		rec-mode recutils
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	BASH CURL DOCS GCRYPT MDB NLS TEST
OPTIONS_DEFAULT=	CURL GCRYPT MDB
OPTIONS_SUB=	yes

BASH_DESC=	Build ${PORTNAME} bash(1) builtins
BASH_BUILD_DEPENDS=	${LOCALBASE}/include/bash/config.h:shells/bash
BASH_CONFIGURE_ON=	--with-bash-headers=${LOCALBASE}/include/bash
BASH_CONFIGURE_OFF=	--disable-bash-builtins

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENV_OFF=	ac_cv_lib_curl_curl_global_init=no

GCRYPT_DESC=	Encryption support via GNU crypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_CONFIGURE_OFF=	--disable-encryption

MDB_DESC=	MS Access database (.mdb) support
MDB_BUILD_DEPENDS=	help2man:misc/help2man
MDB_LIB_DEPENDS=	libmdb.so:databases/mdbtools
MDB_CONFIGURE_ENV_OFF=	ac_cv_lib_mdb_mdb_get_version=no

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

TEST_BUILD_DEPENDS=	${LOCALBASE}/include/check.h:devel/check
TEST_TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's,mdb_init,mdb_get_version,' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/*.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
