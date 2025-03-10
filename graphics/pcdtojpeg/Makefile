PORTNAME=	pcdtojpeg
DISTVERSION=	1_0_17
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Converts PCD (Kodak Photo CD) image files
WWW=		https://pcdtojpeg.sourceforge.io/Home.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../gpl.txt

USES=		zip localbase:ldflags jpeg
CXXFLAGS+=	-DmNoPThreads
WRKSRC_SUBDIR=	src
LIBS+=		-ljpeg
DOCLIST=	Documentation Documentation.html ReadMe.txt Release.txt

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && \
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} ${LIBS} -o ${PORTNAME} main.cpp pcdDecode.cpp)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${WRKSRC}/../Documentation/Images # empty dir
	${TAR} -C ${WRKSRC}/.. -cf - ${DOCLIST} | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -

.include <bsd.port.mk>
