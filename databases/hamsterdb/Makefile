# New ports collection makefile for:	hamsterdb
# Date created:				17 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hamsterdb
PORTVERSION=	1.1.14
CATEGORIES=	databases
MASTER_SITES=	http://hamsterdb.com/public/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Lightweight Embedded Database Engine

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

HAM_DOCS=	README INSTALL ChangeLog TODO AUTHORS CREDITS

post-extract:
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/unittests/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${HAM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
