# Created by: trevor
# $FreeBSD$

PORTNAME=	streamripper
PORTVERSION=	1.64.6
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28current%29/${PORTVERSION} \
		http://gd.tuwien.ac.at/hci/cdk/:cdk
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		cdk-${CDK_VERSION}.tgz:cdk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Splits SHOUTcast stream into tracks

LICENSE=	GPLv2

LIB_DEPENDS=	libmad.so:audio/libmad \
		libtre.so:textproc/libtre

OPTIONS_DEFINE=	FAAD VORBIS
OPTIONS_DEFAULT=FAAD VORBIS

USES=		iconv ncurses pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-libmad \
		--without-included-tre \
		--with-included-argv \
		--with-included-cdk

PLIST_FILES=	bin/streamripper \
		man/man1/streamripper.1.gz

CFLAGS+=	-DANSI_PROTOTYPES
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Lcdk-${CDK_VERSION} -L${LOCALBASE}/lib

CDK_VERSION=	5.0-20060507

FAAD_CONFIGURE_OFF=	ac_cv_lib_faad_NeAACDecDecode2=no
FAAD_LIB_DEPENDS=	libfaad.so:audio/faad

VORBIS_CONFIGURE_WITH=	ogg
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

post-extract:
	${MV} ${WRKDIR}/cdk-${CDK_VERSION} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/if test/s|==|=|g' ${WRKSRC}/configure
#	avoid potential name conflict with ncurses
	@${LN} -sv ${WRKSRC}/cdk-5.0-20060507/include/menu.h \
		${WRKSRC}/cdk-5.0-20060507/include/cdkmenu.h
	@${REINPLACE_CMD} -e "s|<menu.h>|<cdkmenu.h>|g" \
		${WRKSRC}/cdk-5.0-20060507/include/cdk.h

pre-configure:
	(cd ${WRKSRC}/cdk-${CDK_VERSION} && ${SETENV} CC="${CC}" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" ${SH} ./configure)

pre-build:
	(cd ${WRKSRC}/cdk-${CDK_VERSION} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamripper ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/streamripper.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
