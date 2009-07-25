# New ports collection makefile for:	ocfpcsc
# Date created:		2009-01-07
# Whom:			Marcin Cieslak <saper@SYSTEM.PL>
#
# $FreeBSD$
#

PORTNAME=	ocfpcsc
PORTVERSION=	0.0.1
CATEGORIES=	devel security java
MASTER_SITES=	http://www.musclecard.com/middleware/files/
DISTNAME=	OCFPCSC1-${PORTVERSION}

MAINTAINER=	saper@SYSTEM.PL
COMMENT=	Open Card Framework to PC/SC bridge

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes
USE_JAVA=	1.2+
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC

PORTEXAMPLES=	opencard.properties
PORTDOCS=	README

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MOZILLA_PLUGIN)
PLIST_SUB+=	PLUGIN=""
.else
PLIST_SUB+=	PLUGIN="@comment "
.endif

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/opencard.properties ${EXAMPLESDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/libOCFPCSC1.so ${PREFIX}/lib/libOCFPCSC1.so.1
	@${INSTALL_DATA} ${WRKSRC}/libWINSCARD.so ${PREFIX}/lib/libWINSCARD.so.1
	@${LN} -fs ${PREFIX}/lib/libOCFPCSC1.so.1 ${PREFIX}/lib/libOCFPCSC1.so
	@${LN} -fs ${PREFIX}/lib/libWINSCARD.so.1 ${PREFIX}/lib/libWINSCARD.so
.if !defined (WITHOUT_MOZILLA_PLUGIN)
	@${MKDIR} ${PREFIX}/lib/browser_plugins
	@${LN} -fs ${PREFIX}/lib/libOCFPCSC1.so.1 ${PREFIX}/lib/browser_plugins/libOCFPCSC1.so
	@${LN} -fs ${PREFIX}/lib/libWINSCARD.so.1 ${PREFIX}/lib/browser_plugins/libWINSCARD.so
.endif

.include <bsd.port.post.mk>
