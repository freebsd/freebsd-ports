# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	qwdtools
CATEGORIES=	games converters
COMMENT=	Convert QuakeWorld demos from QWD format to MVD format
DESCR=		${.CURDIR}/pkg-descr
PKGMESSAGE=	/nonexistent

BUILD_WRKSRC=	${WRKSRC}/tools/qwdtools/source
GH_PROJECT=	mvdsv

CFLAGS+=	-DQWE_VERSION=\\\"${PORTVERSION}\\\"

MASTERDIR=	${.CURDIR}/../mvdsv

.include "${MASTERDIR}/Makefile"
