# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hamsterdb
PORTVERSION=	1.1.15
CATEGORIES=	databases
MASTER_SITES=	http://hamsterdb.com/public/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Lightweight Embedded Database Engine

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes

HAM_DOCS=	README INSTALL ChangeLog TODO AUTHORS CREDITS

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/unittests/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${HAM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
