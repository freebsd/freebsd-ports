# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cccc
PORTVERSION=	3.1.4
CATEGORIES=	devel textproc www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C and C++ Code Counter

BUILD_DEPENDS=	antlr:${PORTSDIR}/devel/pccts \
		dlg:${PORTSDIR}/devel/pccts

USES=		gmake
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS=	CCC="${CXX}"

PORTDOCS=	readme.txt changes.txt
PLIST_FILES=	bin/cccc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cccc/cccc ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
