# Created by: Marcin Cieslak <saper@saper.info>
# $FreeBSD$

PORTNAME=	ocfpcsc
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	devel security java
MASTER_SITES=	http://www.musclecard.com/middleware/files/
DISTNAME=	OCFPCSC1-${PORTVERSION}

MAINTAINER=	saper@saper.info
COMMENT=	Open Card Framework to PC/SC bridge

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	IBMOCF
LICENSE_NAME=	IBM OpenCard Framework
LICENSE_FILE=	${FILESDIR}/IBMOCF
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		gmake
USE_JAVA=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC

OPTIONS_DEFINE=	DOCS EXAMPLES MOZILLA_PLUGIN
OPTIONS_DEFAULT=MOZILLA_PLUGIN

OPTIONS_SUB=	yes

PORTEXAMPLES=	opencard.properties
PORTDOCS=	README

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/PcscExceptions.cpp
	${TOUCH} ${WRKSRC}/dummy.cpp

do-configure:
	@${REINPLACE_CMD} \
		-e 's,CC        =.*,CC        = ${CXX},' \
		-e 's,PCSC_HDRS =.*,PCSC_HDRS = -I${LOCALBASE}/include/PCSC,' \
		-e 's,PCSC_LIBS =.*,PCSC_LIBS = -L${LOCALBASE}/lib -lpcsclite,' \
		-e 's,JDK_HOME  =.*,JDK_HOME  = ${JAVA_HOME},'\
		-e 's,genunix,freebsd,' \
			 ${WRKSRC}/Makefile

post-build:
	# Create and install a dummy library for applets that
	# think they require WINSCARD.DLL
	(cd ${WRKSRC} && ${LD} -Bsymbolic -shared dummy.o -o libWINSCARD.so)

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/opencard.properties ${STAGEDIR}${EXAMPLESDIR}/opencard.properties
	${INSTALL_DATA} ${WRKSRC}/libOCFPCSC1.so ${STAGEDIR}${PREFIX}/lib/libOCFPCSC1.so.1
	${INSTALL_DATA} ${WRKSRC}/libWINSCARD.so ${STAGEDIR}${PREFIX}/lib/libWINSCARD.so.1
	${LN} -fs libOCFPCSC1.so.1 ${STAGEDIR}${PREFIX}/lib/libOCFPCSC1.so
	${LN} -fs libWINSCARD.so.1 ${STAGEDIR}${PREFIX}/lib/libWINSCARD.so
.if ${PORT_OPTIONS:MMOZILLA_PLUGIN}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/browser_plugins
	@${LN} -fs ../../lib/libOCFPCSC1.so.1 ${STAGEDIR}${PREFIX}/lib/browser_plugins/libOCFPCSC1.so
	@${LN} -fs ../../lib/libWINSCARD.so.1 ${STAGEDIR}${PREFIX}/lib/browser_plugins/libWINSCARD.so
.endif

.include <bsd.port.mk>
