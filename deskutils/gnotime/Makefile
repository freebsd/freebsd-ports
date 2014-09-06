# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gnotime
PORTVERSION=	2.4.1
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/gttr/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		SF/qof/qof/${QOF_VERSION}:qof
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${QOF_DISTNAME}${EXTRACT_SUFX}:qof

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time tracker for gnome2

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

USES=		gettext gmake libtool pathfix pkgconfig
USE_XORG=	xscrnsaver
USE_GNOME=	gnomeprefix gtkhtml3 intlhack libgnomeui
USE_AUTOTOOLS=	libtoolize libltdl
GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure ../${QOF_DISTNAME}/configure
CONFIGURE_ENV=	GUILE_CFLAGS="$$(guile-config compile)" \
		GUILE_LIBS="$$(guile-config link)" \
		LIBQOF_CFLAGS="${LIBQOF_CFLAGS}" \
		LIBQOF_LIBS="${LIBQOF_LIBS}"
CONFIGURE_ARGS=	--disable-silent-rules
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnotime.schemas

QOF_VERSION=	0.7.5
QOF_DISTNAME=	qof-${QOF_VERSION}
QOF_WRKSRC=	${WRKDIR}/${QOF_DISTNAME}
LIBQOF_CFLAGS=	-I${QOF_WRKSRC}/qof
LIBQOF_LIBS=	-L${QOF_WRKSRC}/qof/.libs -lqof

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am/s|install-data-local||' \
		${WRKSRC}/gconf/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^AM_CFLAGS =/s|-g||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		'/CFLAGS=/s|-g2||' ${QOF_WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|__isleap|qof_date_isleap|' ${QOF_WRKSRC}/qof/qofdate.c
	@${REINPLACE_CMD} -e \
		's|^inline|static inline|' ${QOF_WRKSRC}/qof/qofmath128.h
	@${FIND} ${QOF_WRKSRC} -name "Makefile.in" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		'/^AM_CFLAGS =/s|-g|| ; \
		 s|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|'

pre-configure:
	@(cd ${QOF_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		./configure --prefix=${PREFIX} --disable-error-on-warning \
		--disable-sqlite --disable-gdasql)

pre-build:
	(cd ${QOF_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	${FIND} ${QOF_WRKSRC} -type f -name '*.la' | \
		${XARGS} ${GREP} -l 'libtool library' | ${XARGS} ${RM}

pre-install:
	(cd ${QOF_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
