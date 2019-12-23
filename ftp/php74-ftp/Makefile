# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	ftp

MASTERDIR=	${.CURDIR}/../../lang/php74

PKGNAMESUFFIX=	-ftp

TEST_TARGET=    test

post-patch:
	@${REINPLACE_CMD} s/HAVE_OPENSSL_EXT/__FreeBSD__/ \
		${WRKSRC}/ftp.* ${WRKSRC}/php_ftp.*

.include "${MASTERDIR}/Makefile"
