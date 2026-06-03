PORTNAME=	groonga-normalizer-mysql
#DISTVERIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	databases textproc
MASTER_SITES=	https://github.com/groonga/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL compatible normalizer plugin for Groonga
WWW=		https://github.com/groonga/groonga-normalizer-mysql

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/doc/text/lgpl-2.0.txt

LIB_DEPENDS=	libgroonga.so:textproc/groonga

USES=		cmake

PLIST_FILES=	lib/groonga/plugins/normalizers/mysql.so \
		libdata/pkgconfig/groonga-normalizer-mysql.pc

.include <bsd.port.mk>
