PORTNAME=	hebcal
PORTVERSION=	4.13
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	rtd24@columbia.edu
COMMENT=	Perpetual Jewish calendar
WWW=		https://hebcal.github.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake perl5
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

USE_GITHUB=	yes

PLIST_FILES=	bin/hebcal \
		share/man/man1/hebcal.1.gz

.include <bsd.port.mk>
