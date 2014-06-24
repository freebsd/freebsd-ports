# $FreeBSD$

PORTNAME=	make
PORTVERSION=	3.82
CATEGORIES=	devel ports-mgmt
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g
PKGNAMESUFFIX=	-minimal

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimalist version of gnu make

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gmake-[0-9]*

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=	--program-prefix=g \
			--disable-nls

USES=	tar:bzip2

PLIST_FILES=	bin/gmake \
		man/man1/gmake.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make ${STAGEDIR}${PREFIX}/bin/gmake
	${INSTALL_MAN} ${WRKSRC}/make.1 ${STAGEDIR}${PREFIX}/man/man1/gmake.1

.include <bsd.port.mk>

