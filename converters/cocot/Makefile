PORTNAME=	cocot
DISTVERSIONPREFIX=	${PORTNAME}-1.2-
DISTVERSION=	20171118
CATEGORIES=	converters

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Code Converter on TTY
WWW=		https://github.com/vmi/cocot

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv
USE_GITHUB=	yes
GH_ACCOUNT=	vmi

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cocot ${DOCSDIR}/ja/README.ja

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.ja ${STAGEDIR}${DOCSDIR}/ja

.include <bsd.port.mk>
