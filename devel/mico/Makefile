# New ports collection makefile for:   mico
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mico
PORTVERSION=	2.3.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.mico.org/

MAINTAINER=	sem@ciam.ru
COMMENT=	Fully compliant implementation of CORBA2.3 with some CORBA3.0 features

DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		doc-html.tar.gz

WRKSRC=			${WRKDIR}/${PORTNAME}
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes
USE_GMAKE=		yes
.if defined(WITH_GCC32)
USE_GCC=		3.2
.endif
CONFIGURE_ARGS+=	--enable-cd --disable-mini-stl --enable-threads \
			--enable-ccm
CONFIGURE_ENV+=		CXXFLAGS=${CPPFLAGS}

.if defined(WITH_X11)
USE_XLIBS=		yes
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

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SSL)
MICO_SSL=		"@comment "
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl=${OPENSSLBASE} --enable-csiv2
# CORBASecV2 doesn't build with gcc32 port because FlexLexer.h absent
.if !( ${OSVERSION} < 500035 && defined(WITH_GCC32) )
CONFIGURE_ARGS+=	--enable-csl2
.endif
.endif

PLIST_SUB+=	MICO_X11=${MICO_X11} MICO_QT=${MICO_QT} MICO_GTK=${MICO_GTK} \
		MICO_TCL=${MICO_TCL} MICO_SSL=${MICO_SSL}

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

pre-fetch:
	@${ECHO} "============================================================================"
.if ${OSVERSION} < 500035
	@${ECHO} "Use WITH_GCC32=yes to build Mico with gcc 3.2 for better stability."
	@${ECHO}
.endif
	@${ECHO} "Following options are allowed:"
	@${ECHO} "WITHOUT_SSL=yes, WITH_X11=yes, WITH_QT=yes, WITH_GTK=yes, WITH_TCL=yes"
	@${ECHO} "============================================================================"

post-extract:
	${TAR} xzf ${DISTDIR}/doc-html.tar.gz -C ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e "s#-O2#${CFLAGS}#" ${WRKSRC}/configure

post-configure:
	${FIND} ${WRKSRC}/demo -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s#/doc/mico/examples#/share/examples/mico#"
	${REINPLACE_CMD} -e "s#/doc/mico/examples#/share/examples/mico#" ${WRKSRC}/demo/MakeVars
	${REINPLACE_CMD} -e "s#ministl##" ${WRKSRC}/include/Makefile
	${RM} ${WRKSRC}/include/mico/*.orig

post-install:
	@for i in `${GREP} '^lib/lib.*so$$' ${TMPPLIST}`; do \
		${LN} -fs ${PREFIX}/$$i ${PREFIX}/$$i.1; \
	done; \
	for i in `${GREP} ^bin/ ${TMPPLIST}`; do \
		(${STRIP_CMD} ${PREFIX}/$$i || ${TRUE}) 2> /dev/null; \
	done
.if !defined(NOPORTDOCS)
	${GMAKE} -C ${WRKSRC} install-doc
	${MKDIR} ${PREFIX}/share/doc/mico/html
	${INSTALL_DATA} ${WRKDIR}/doc/doc/* ${PREFIX}/share/doc/mico/html
.endif

.include <bsd.port.post.mk>
