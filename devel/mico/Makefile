# New ports collection makefile for:   mico
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mico
PORTVERSION=	2.3.12
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/

PATCH_SITES=	http://mico.org/errata/
PATCHFILES=	mico-2.3.12-secfix1.diff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure, reliable, production-quality, standards-based CORBA middleware

PATCH_DIST_STRIP=	-p1
WRKSRC=			${WRKDIR}/${PORTNAME}
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		autoconf
CONFIGURE_ENV+=		EGREP=`which egrep`

OPTIONS=	NOSERVICES "Without services, plain ORB" off \
		SSL "Build with SSL" on \
		X11 "Build with X11 support" off \
		QT "Build with QT support" off \
		GTK "Build with GTK support" off \
		DEBUG "Build debug version" off

# need for OPTIONS work
PORT_DBDIR?=	/var/db/ports

OPTIONSFILE?=	${PORT_DBDIR}/${PORTNAME}/options
.if exists(${OPTIONSFILE}) && !make(rmconfig)
.include "${OPTIONSFILE}"
.endif
.if exists(${OPTIONSFILE}.local)
.include "${OPTIONSFILE}.local"
.endif
# ================

NOT_FOR_ARCHS=		sparc64

CONFIGURE_ARGS=		--enable-cd --disable-mini-stl --enable-threads

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif
.if !defined(WITH_NOSERVICES)
CONFIGURE_ARGS+=	--enable-ccm
.else
CONFIGURE_ARGS+=	--disable-coss
MICO_SERVICE=		"@comment "
.endif

CONFIGURE_ENV+=		CXXFLAGS="${CPPFLAGS} -Wno-unused"

.if defined(WITH_X11)
USE_XORG=		x11
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
MICO_X11=		"@comment "
.endif
.if defined(WITH_QT)
USE_QT_VER=			3
CONFIGURE_ARGS+=	--with-qt=${LOCALBASE}
QTCPPFLAGS+=		${CPPFLAGS}
.else
MICO_QT=		"@comment "
.endif
.if defined(WITH_GTK)
USE_GNOME=		gtk12
CONFIGURE_ARGS+=	--with-gtk=${LOCALBASE}
.else
MICO_GTK=		"@comment "
.endif
.if defined(WITH_TCL)
LIB_DEPENDS=		tcl83:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=	--with-tcl
CPPFLAGS+=		-I${LOCALBASE}/include/tcl8.3
CONFIGURE_ENV+=		CPPFLAGS=${CPPFLAGS}
.else
MICO_TCL=		"@comment "
.endif

.if defined(WITHOUT_SSL) || defined(WITH_NOSERVICES)
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
	@${REINPLACE_CMD} -e "s#\"-O2\"#\"${CFLAGS}\"#;s#\"-pthread#\"${PTHREAD_LIBS}#" ${WRKSRC}/configure.in

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
.if !defined(NOPORTDOCS)
	${GMAKE} -C ${WRKSRC} install-doc
.endif

.include <bsd.port.mk>
