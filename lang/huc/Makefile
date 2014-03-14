# Created by: Frederic Cambus
# $FreeBSD$

PORTNAME=	huc
PORTVERSION=	3.21
DISTVERSIONSUFFIX=	-src
CATEGORIES=	lang emulators
MASTER_SITES=	http://www.zeograd.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC Engine C compiler which can create ROMs (hucard) or CD images

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

USES=		gmake zip
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
.for file in huc isolink nesasm pceas pcxtool
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	@(cd ${WRKSRC}/include \
		&& ${COPYTREE_SHARE} . ${PREFIX}/include/${PORTNAME})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc \
		&& ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
