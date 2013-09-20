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

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	readme.txt changes.txt
PLIST_FILES=	bin/cccc

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|=g++|=${CXX}|' ${WRKSRC}/*/posix*.mak

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cccc/cccc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
