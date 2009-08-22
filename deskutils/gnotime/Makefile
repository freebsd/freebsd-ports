# New ports collection makefile for:	gnotime
# Date created:		1 March 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnotime/Makefile,v 1.21 2007/05/19 21:36:03 marcus Exp $
#

PORTNAME=	gnotime
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/gttr/${PORTNAME}/${PORTNAME}-${PORTVERSION}:gttr SF/gttr/${PORTNAME}/${PORTNAME}-${PORTVERSION}:qof
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gttr \
		${QOF_DISTNAME}${EXTRACT_SUFX}:qof

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A time tracker for gnome2

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile

USE_XORG=	xscrnsaver
USE_GNOME=	gnomehack gnomeprefix gtkhtml3 intlhack libgnomeui
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22 libltdl:22
LIBTOOLFILES=	configure ../${QOF_DISTNAME}/configure
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBQOF_CFLAGS="${LIBQOF_CFLAGS}" LIBQOF_LIBS="${LIBQOF_LIBS}"
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes

MAN1=		gnotime.1 gnotime-remote.1
GCONF_SCHEMAS=	gnotime.schemas

QOF_DISTNAME=	qof-0.7.5
QOF_WRKSRC=	${WRKDIR}/${QOF_DISTNAME}

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
LIBQOF_CFLAGS=	-I${QOF_WRKSRC}/qof
LIBQOF_LIBS=	-L${QOF_WRKSRC}/qof/.libs -lqof

post-patch:
	@${REINPLACE_CMD} -e \
		'/CFLAGS=/s|-g2||g' ${QOF_WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|__isleap|qof_date_isleap|g' ${QOF_WRKSRC}/qof/qofdate.c
	@${FIND} ${QOF_WRKSRC} -name "Makefile.in" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		'/^AM_CFLAGS =/s|-g||g ; \
		 s|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g'

pre-configure:
	@(cd ${QOF_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		./configure --prefix=${PREFIX} --disable-error-on-warning \
		--disable-sqlite --disable-gdasql)

pre-build:
	@(cd ${QOF_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

pre-install:
	@(cd ${QOF_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.include <bsd.port.mk>
