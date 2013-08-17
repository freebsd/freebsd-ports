# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbf
PORTVERSION=	0.9.0
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}.berlios
DISTFILES=	${PORTNAME}-core-${PORTVERSION}.src.zip \
		lib${PORTNAME}-0.0.1.src.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show and convert the content of dBASE III, IV, and 5.0 files

OPTIONS_DEFINE=	NLS

WRKSRC=		${WRKDIR}/lib${PORTNAME}

USE_ZIP=	yes
USES=        pathfix
USE_GNOME=	intltool
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_DOC_TO_MAN=""
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ENV+=	ac_cv_header_libintl_h=no
PLIST_SUB+=	NLS="@comment "
.endif

_make_jobs=	-j${MAKE_JOBS_NUMBER}

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
		CPPFLAGS="-I${WRKSRC}/include" \
		LDFLAGS="-L${WRKSRC}/src/.libs" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		ac_cv_lib_dbf_dbf_Open=yes \
		./configure --prefix=${PREFIX})

post-build:
	@(cd ${WRKDIR}/${PORTNAME}-core && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${_make_jobs} ${ALL_TARGET})

post-install:
	@(cd ${WRKDIR}/${PORTNAME}-core && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.mk>
