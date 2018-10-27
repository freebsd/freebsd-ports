# Created by: ijliao
# $FreeBSD$

PORTNAME=	gnucap
DISTVERSION=	2013-04-23
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.gnucap.org/devel/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Circuit Analysis Package

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	defined in discarded section
BROKEN_mips64=	defined in discarded section

USES=		gmake
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	prefix=${STAGEDIR}${PREFIX}

MAKE_ARGS=	CCFLAGS="${CXXFLAGS}" CCC=c++
CXXFLAGS+=	-fPIC -I${PREFIX}/include -I${WRKSRC}/include
ALL_TARGET=	gnucap

PLIST_FILES=	bin/gnucap bin/gnucap-modelgen \
		lib/libgnucap-default-plugins.so \
		lib/libgnucap.so

PORTDOCS=	README
EXAMPLES=	runl *c *.ckt *.doc

OPTIONS_DEFINE=	DOCS

post-patch:
	${FIND} -s ${WRKSRC} -name 'configure'|${XARGS} \
		${REINPLACE_CMD} -e 's|g++|${CXX}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/O/gnucap ${WRKSRC}/modelgen/O/gnucap-modelgen \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib/O/libgnucap.so ${WRKSRC}/apps/O/*.so \
		${STAGEDIR}${PREFIX}/lib

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
