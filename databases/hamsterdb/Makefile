# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hamsterdb
PORTVERSION=	1.1.15
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://files.hamsterdb.com/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Lightweight Embedded Database Engine

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_LDCONFIG=	yes

HAM_DOCS=	README INSTALL ChangeLog TODO AUTHORS CREDITS

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/unittests/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${HAM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
