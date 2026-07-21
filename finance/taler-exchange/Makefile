PORTNAME=	taler-exchange
DISTVERSION=	1.5.2
CATEGORIES=	finance
MASTER_SITES=	http://ftpmirror.gnu.org/taler/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Privacy-preserving distributed payment system
WWW=		https://www.taler.net/en/index.html

LICENSE=	GPLv3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		jq>0:textproc/jq
RUN_DEPENDS=	jq>0:textproc/jq
LIB_DEPENDS=	libgnunetpq.so:net/gnunet \
		libmicrohttpd.so:www/libmicrohttpd \
# These are lib-dependencies of the benchmark programs
LIB_DEPENDS+=	libjansson.so:devel/jansson \
		libunistring.so:devel/libunistring \
		libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libsodium.so:security/libsodium

EXTRACT_SUFX=	.tar.gz
USES=		compiler:c11 cpe gettext-runtime libtool pgsql pkgconfig python \
		shebangfix sqlite tar

CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBRARY_PATH=${PREFIX}/lib
CONFIGURE_ARGS=	--with-gnunet=${PREFIX} \
		--with-microhttpd=${PREFIX} \
		--with-microhttpd2=${PREFIX}

CFLAGS+=	-I${PREFIX}
LDFLAGS+=	-L${PREFIX} -pthread

SHEBANG_FILES=	src/kyclogic/taler-exchange-helper-measure-challenger-email-context-check \
		src/kyclogic/taler-exchange-helper-measure-challenger-postal-context-check \
		src/kyclogic/taler-exchange-helper-measure-challenger-sms-context-check \
		src/kyclogic/taler-exchange-helper-measure-clear-continue \
		src/kyclogic/taler-exchange-helper-measure-defaults-but-investigate \
		src/kyclogic/taler-exchange-helper-measure-freeze \
		src/kyclogic/taler-exchange-helper-measure-inform-investigate \
		src/kyclogic/taler-exchange-helper-measure-none \
		src/kyclogic/taler-exchange-helper-measure-preserve-but-investigate \
		src/kyclogic/taler-exchange-helper-measure-preserve-set-expiration \
		src/kyclogic/taler-exchange-helper-measure-test-form \
		src/kyclogic/taler-exchange-helper-measure-test-oauth \
		src/kyclogic/taler-exchange-helper-measure-tops-3rdparty-check \
		src/kyclogic/taler-exchange-helper-measure-tops-address-check \
		src/kyclogic/taler-exchange-helper-measure-tops-kyx-check \
		src/kyclogic/taler-exchange-helper-measure-tops-postal-check \
		src/kyclogic/taler-exchange-helper-measure-tops-sms-check \
		src/kyclogic/taler-exchange-helper-measure-update-from-context \
		src/kyclogic/taler-exchange-helper-measure-validate-accepted-tos \
		src/kyclogic/taler-exchange-kyc-challenger-email-converter \
		src/kyclogic/taler-exchange-kyc-challenger-postal-converter \
		src/kyclogic/taler-exchange-kyc-challenger-sms-converter \
		src/kyclogic/taler-exchange-kyc-kycaid-converter.sh \
		src/kyclogic/taler-exchange-kyc-oauth2-challenger.sh \
		src/kyclogic/taler-exchange-kyc-oauth2-nda.sh \
		src/kyclogic/taler-exchange-kyc-oauth2-test-converter.sh \
		src/kyclogic/taler-exchange-kyc-persona-converter.sh \
		contrib/taler-auditor-dbconfig \
		contrib/taler-exchange-dbconfig \
		contrib/taler-terms-generator \
		src/testing/taler-unified-setup.sh \
		src/auditor/taler-helper-auditor-render.py

.include <bsd.port.mk>
