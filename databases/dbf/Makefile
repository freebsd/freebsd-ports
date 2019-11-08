# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbf
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}.berlios
DISTFILES=	${PORTNAME}-core-${PORTVERSION}.src.zip \
		lib${PORTNAME}-0.0.1.src.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show and convert the content of dBASE III, IV, and 5.0 files

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/lib${PORTNAME}

USES=		gnome libtool pathfix zip
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_DOC_TO_MAN=""
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
.else
CONFIGURE_ENV+=	ac_cv_header_libintl_h=no
.endif

post-extract:
	@${FIND} ${WRKDIR} -name "configure" -or -name "install-sh" | \
		${XARGS} ${CHMOD} ${BINMODE}

post-patch:
	@${REINPLACE_CMD} -e \
		'/typedef u_int/d' ${WRKSRC}/src/endian.h

post-configure:
	@(cd ${WRKDIR}/${PORTNAME}-core && ${SETENV} ${CONFIGURE_ENV} \
		CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${WRKSRC}/include ${CPPFLAGS}" \
		LDFLAGS="-L${WRKSRC}/src/.libs ${LDFLAGS}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		ac_cv_lib_dbf_dbf_Open=yes \
		./configure --prefix=${PREFIX})

post-build:
	@(cd ${WRKDIR}/${PORTNAME}-core && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} -j${MAKE_JOBS_NUMBER} ${MAKE_ARGS} \
		${ALL_TARGET})

post-install:
	@(cd ${WRKDIR}/${PORTNAME}-core && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} -j${MAKE_JOBS_NUMBER} ${MAKE_ARGS} \
		${INSTALL_TARGET})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdbf.so.0

.include <bsd.port.mk>
