# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	ftp

MASTERDIR=	${.CURDIR}/../../lang/php56

PKGNAMESUFFIX=	-ftp

post-patch:
	@${REINPLACE_CMD} s/HAVE_OPENSSL_EXT/__FreeBSD__/ \
		${WRKSRC}/ftp.* ${WRKSRC}/php_ftp.*

.include "${MASTERDIR}/Makefile"
