# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	cocot
PORTVERSION=	20120313
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}-1.1-${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Code Converter on TTY

OPTIONS_DEFINE=	DOCS

USES=		iconv
WRKSRC=		${WRKDIR}/vmi-${PORTNAME}-8bc9f64
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
