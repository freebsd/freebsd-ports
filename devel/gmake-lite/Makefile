# $FreeBSD$

PORTNAME=	make
PORTVERSION=	4.2.1
CATEGORIES=	devel ports-mgmt
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g
PKGNAMESUFFIX=	-lite

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimalist version of gnu make

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-prefix=g \
			--program-suffix=-lite \
			--without-guile \
			--disable-nls
# fmake does not like PO_DEPENDS_ON_POT being undefined
MAKE_ARGS=	PO_DEPENDS_ON_POT=

USES=	cpe tar:bzip2
CPE_VENDOR=	gnu

PLIST_FILES=	bin/gmake-lite \
		man/man1/gmake-lite.1.gz

post-patch:
	${REINPLACE_CMD} -e "s/ doc / /g" ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make ${STAGEDIR}${PREFIX}/bin/gmake-lite
	${INSTALL_MAN} ${WRKSRC}/make.1 ${STAGEDIR}${PREFIX}/man/man1/gmake-lite.1

.include <bsd.port.mk>
