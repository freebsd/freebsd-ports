PORTNAME=	cocot
PORTVERSION=	20120313
DISTVERSIONPREFIX=	${PORTNAME}-1.1-
PORTREVISION=	1
CATEGORIES=	converters

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Code Converter on TTY
WWW=		https://github.com/vmi/cocot

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	vmi

USES=		iconv
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${ICONV_PREFIX}/include
LDFLAGS+=	-L${ICONV_PREFIX}/lib

DOCS_EN=	COPYING ChangeLog
DOCS_JA=	ChangeLog.ja README.ja

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/ja
.endfor

.include <bsd.port.mk>
