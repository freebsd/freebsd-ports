# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mico
PORTVERSION=	2.3.12
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/

PATCH_SITES=	http://mico.org/errata/
PATCHFILES=	mico-2.3.12-secfix1.diff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure, reliable, production-quality, standards-based CORBA middleware

BROKEN=	fails to build

PATCH_DIST_STRIP=	-p1
WRKSRC=			${WRKDIR}/${PORTNAME}
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		autoconf
CONFIGURE_ENV+=		EGREP=`which egrep`

OPTIONS_DEFINE=	SERVICES SSL X11 GTK1 DEBUG TCL DOCS
OPTIONS_DEFAULT=	SSL SERVICES
SERVICES_DESC=	With services, plain ORB
GTK1_DESC=	Build with GTK1 support
TCL_DESC=	Build with TCL support

NO_STAGE=	yes
.include <bsd.port.options.mk>

NOT_FOR_ARCHS=		sparc64

CONFIGURE_ARGS=		--enable-cd --disable-mini-stl --enable-threads

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif
.if ${PORT_OPTIONS:MSERVICES}
CONFIGURE_ARGS+=	--enable-ccm
.else
CONFIGURE_ARGS+=	--disable-coss
MICO_SERVICE=		"@comment "
.endif

CXXFLAGS+=		${CPPFLAGS} -Wno-unused

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
MICO_X11=		"@comment "
.endif
MICO_QT=		"@comment "
.if ${PORT_OPTIONS:MGTK1}
USE_GNOME=		gtk12
CONFIGURE_ARGS+=	--with-gtk=${LOCALBASE}
.else
MICO_GTK=		"@comment "
.endif
.if ${PORT_OPTIONS:MTCL}
USES+=			tcl
CONFIGURE_ARGS+=	--with-tcl
CPPFLAGS+=		-I${TCL_INCLUDEDIR}
LDFLAGS+=		-L${LOCALBASE}/lib
.else
MICO_TCL=		"@comment "
.endif

.if empty(PORT_OPTIONS:MSSL) || empty(PORT_OPTIONS:MSERVICES)
MICO_SSL=		"@comment "
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl=${OPENSSLBASE}
CONFIGURE_ARGS+=	--enable-csiv2 --enable-csl2
.endif

PLIST_SUB+=	MICO_X11=${MICO_X11} MICO_QT=${MICO_QT} MICO_GTK=${MICO_GTK} \
		MICO_TCL=${MICO_TCL} MICO_SSL=${MICO_SSL} \
		MICO_SERVICE=${MICO_SERVICE}

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-patch:
	@${REINPLACE_CMD} -e "s#\"-O2\"#\"${CFLAGS}\"#" ${WRKSRC}/configure.in

post-configure:
	@${FIND} ${WRKSRC}/demo -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s#/doc/mico/examples#${EXAMPLESDIR:S#^${PREFIX}##}#"
	@${REINPLACE_CMD} -e "s#/doc/mico/examples#${EXAMPLESDIR:S#^${PREFIX}##}#" ${WRKSRC}/demo/MakeVars
	@${REINPLACE_CMD} -e "s#ministl##" ${WRKSRC}/include/Makefile
	@${RM} -f ${WRKSRC}/include/mico/*.orig ${WRKSRC}/include/coss/*.orig

post-install:
	@for i in `${GREP} '^lib/lib.*so$$' ${TMPPLIST}`; do \
		${LN} -fs ${PREFIX}/$$i ${PREFIX}/$$i.1; \
	done; \
	for i in `${GREP} ^bin/ ${TMPPLIST}`; do \
		(${STRIP_CMD} ${PREFIX}/$$i || ${TRUE}) 2> /dev/null; \
	done
.if ${PORT_OPTIONS:MDOCS}
	${GMAKE} -C ${WRKSRC} install-doc
.endif

.include <bsd.port.mk>
