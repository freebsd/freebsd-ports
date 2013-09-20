# Created by: Ying-Chieh Liao
# $FreeBSD$

PORTNAME=	hte
PORTVERSION=	2.0.22
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/ht-source
DISTNAME=	ht-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A file editor/viewer/analyzer for executables

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ht

OPTIONS_DEFINE=		DOCS LZO2 X11
OPTIONS_DEFAULT=	X11

LZO2_DESC=	External lzo2 compression support
X11_DESC=	X11 textmode support

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON=	does not build on ia64

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLZO2}
LIB_DEPENDS+=	lzo2:${PORTSDIR}/archivers/lzo2
.else
CONFIGURE_ARGS=	--with-included-lzo
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=--disable-x11-textmode
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README
INFO=		ht
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=.*$$|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|^CFLAGS=.*$$|CFLAGS="$$CFLAGS"|g ; \
		 s|-L/usr/X11/lib -L/usr/X11R6/lib|$$LDFLAGS|g' \
			${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ht ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/hthelp.info ${PREFIX}/${INFO_PATH}/ht.info
.endif

.include <bsd.port.mk>
