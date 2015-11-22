# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ada-util
PORTVERSION=	1.8.0
CATEGORIES=	devel

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Utility library for Ada 2005 applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	gprbuild:${PORTSDIR}/devel/gprbuild \
		xmlada>=4.4:${PORTSDIR}/textproc/xmlada \
		${LOCALBASE}/lib/gnat/ahven.gpr:${PORTSDIR}/devel/ahven
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		ada gmake
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ahven
CONFIGURE_ENV=	ac_cv_lib_dl_dlopen=no
LDFLAGS=	-L${LOCALBASE}/lib

GH_ACCOUNT=	stcarrez
GH_TAGNAME=	b6612400

post-patch:
	@${REINPLACE_CMD} -e 's,freebsd\*,dragonfly*|freebsd*,' \
		-e "s/^NR_CPUS=.*/NR_CPUS=${MAKE_JOBS_NUMBER}/" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@prefix@|$${DESTDIR}@prefix@|' \
		-e '/GPRINSTALL/ \
		s|--prefix|--project-subdir=lib/gnat --prefix|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/Content_Type/d' \
		${WRKSRC}/src/http/util-http-rest.adb

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/gnat/manifests

.include <bsd.port.mk>
