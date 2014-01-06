# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flops
PORTVERSION=	2.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://mbsd.msk.ru/dist/
DISTFILES=	${PORTNAME}.c ${PORTNAME}.doc
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Floating point benchmark to give your MFLOPS rating

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

PORTDOCS=	flops.doc
PLIST_FILES=	bin/flops

post-extract:
	@(cd ${DISTDIR} && ${TAR} -cf - ${DISTFILES}) | \
		(cd ${WRKSRC} && ${TAR} -xf -)

post-patch:
	@${REINPLACE_CMD} -e \
		's|^void main|int main|' ${WRKSRC}/flops.c

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DUNIX -o flops flops.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flops ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/flops.doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
