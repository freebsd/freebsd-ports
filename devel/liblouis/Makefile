# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouis
PORTVERSION=	3.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-source Braille Translator And Back-translator

LICENSE=	LGPL3+

BUILD_DEPENDS=	help2man:misc/help2man

USES=		autoreconf gmake libtool pathfix shebangfix
SHEBANG_FILES=	tools/lou_maketable.d/substrings.pl
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
