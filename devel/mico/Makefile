# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mico
PORTVERSION=	2.3.13
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Secure, reliable, production-quality, standards-based CORBA middleware

LICENSE=	GPLv2

USES=	gmake
USE_AUTOTOOLS=		autoconf

USE_LDCONFIG=		yes
WRKSRC=			${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		EGREP=`which egrep`

OPTIONS_DEFINE=	SERVICES SSL X11 GTK1 DEBUG TCL DOCS
OPTIONS_DEFAULT=	SSL SERVICES
SERVICES_DESC=	With services, plain ORB
GTK1_DESC=	Build with GTK1 support
TCL_DESC=	Build with TCL support

.include <bsd.port.options.mk>

NOT_FOR_ARCHS=		sparc64

CONFIGURE_ARGS=		--enable-cd --disable-mini-stl --enable-threads

MICO_LIBS=	mico micoaux micoir

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif
.if ${PORT_OPTIONS:MSERVICES}
CONFIGURE_ARGS+=	--enable-ccm
MICO_LIBS+=		micoccm micocoss
.else
CONFIGURE_ARGS+=	--disable-coss
MICO_SERVICE=		"@comment "
.endif

CXXFLAGS+=		${CPPFLAGS} -Wno-unused

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11
CONFIGURE_ARGS+=	--with-x
MICO_LIBS+=	micox
.else
CONFIGURE_ARGS+=	--without-x
MICO_X11=		"@comment "
.endif
MICO_QT=		"@comment "
.if ${PORT_OPTIONS:MGTK1}
USE_GNOME=		gtk12
CONFIGURE_ARGS+=	--with-gtk=${LOCALBASE}
MICO_LIBS+=		micogtk
.else
MICO_GTK=		"@comment "
.endif
.if ${PORT_OPTIONS:MTCL}
USES+=			tcl
CONFIGURE_ARGS+=	--with-tcl
CPPFLAGS+=		-I${TCL_INCLUDEDIR}
LDFLAGS+=		-L${LOCALBASE}/lib
MICO_LIBS+=		micotcl
.else
MICO_TCL=		"@comment "
.endif
INSTALL_TARGET=		install
.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=	install-doc
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
INSTALL_TARGET+=	install-demo
.endif

.if empty(PORT_OPTIONS:MSSL) || empty(PORT_OPTIONS:MSERVICES)
MICO_SSL=		"@comment "
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif

PLIST_SUB+=	MICO_X11=${MICO_X11} MICO_QT=${MICO_QT} MICO_GTK=${MICO_GTK} \
		MICO_TCL=${MICO_TCL} MICO_SSL=${MICO_SSL} \
		MICO_SERVICE=${MICO_SERVICE}

post-configure:
	${REINPLACE_CMD} -e "s#\"-O2\"#\"${CFLAGS}\"#" ${WRKSRC}/configure.in
	${FIND} ${WRKSRC}/demo -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s#/doc/mico/examples#${EXAMPLESDIR:S#^${PREFIX}##}#"
	${REINPLACE_CMD} -e "s#/doc/mico/examples#${EXAMPLESDIR:S#^${PREFIX}##}#" ${WRKSRC}/demo/MakeVars
	${REINPLACE_CMD} -e "s#ministl##" ${WRKSRC}/include/Makefile
	${RM} -f ${WRKSRC}/include/mico/*.orig ${WRKSRC}/include/coss/*.orig

pre-install:
	${REINPLACE_CMD} -e "s#${PREFIX}#${STAGEDIR}${PREFIX}#" ${WRKSRC}/MakeVars

post-install:
	for i in `${GREP} '^lib/lib.*so$$' ${TMPPLIST}`; do \
		(cd ${STAGEDIR}${PREFIX}/lib/; \
		   ${LN} -s $$i ${STAGEDIR}${PREFIX}/$$i.1); \
	done; \
	for i in `${GREP} ^bin/ ${TMPPLIST}`; do \
		(${STRIP_CMD} ${STAGEDIR}${PREFIX}/$$i || ${TRUE}) 2> /dev/null; \
	done

.include <bsd.port.mk>
