# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	cocot
PORTVERSION=	20120313
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ \
		LOCAL/knu
DISTNAME=	${PORTNAME}-1.1-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Code Converter on TTY

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

USES=		iconv zip
WRKSRC=		${WRKDIR}/vmi-${PORTNAME}-8bc9f64
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${ICONV_PREFIX}/include
LDFLAGS+=	-L${ICONV_PREFIX}/lib

DOCS_EN=	COPYING ChangeLog
DOCS_JA=	ChangeLog.ja README.ja

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/ja
.endfor

.include <bsd.port.mk>
