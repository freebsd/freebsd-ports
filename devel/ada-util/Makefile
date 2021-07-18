# Created by: John Marino <marino@FreeBSD.org>

PORTNAME=	ada-util
PORTVERSION=	1.8.0
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility library for Ada 2005 applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_FreeBSD_12=	'struct stat' has no member named 'st_lspare'
BROKEN_FreeBSD_13=	'struct stat' has no member named 'st_lspare'
BROKEN_FreeBSD_14=	'struct stat' has no member named 'st_lspare'

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		${LOCALBASE}/lib/gnat/ahven.gpr:devel/ahven
LIB_DEPENDS=	libcurl.so:ftp/curl

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

	# Loggers are hardcoded for several packages at the INFO level
	# which is quite useless for things like spawning commands.
	# Set the loggers to filter out everything up less than ERROR

	@${REINPLACE_CMD} -e '/Loggers.Create/s|);|, Util.Log.ERROR_LEVEL);|'\
		${WRKSRC}/src/http/aws/util-http-clients-web.adb \
		${WRKSRC}/src/http/curl/util-http-clients-curl.adb \
		${WRKSRC}/src/http/util-http-clients.adb \
		${WRKSRC}/src/http/util-http-parts.adb \
		${WRKSRC}/src/util-beans-factory.adb \
		${WRKSRC}/src/util-processes.adb \
		${WRKSRC}/src/util-properties-bundles.adb \
		${WRKSRC}/src/xml/util-serialize-io-xml.adb

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/gnat/manifests
	# Scoop up all the source files gprinstall missed. (!)
	${INSTALL_DATA} ${WRKSRC}/src/*.ad[bs] ${WRKSRC}/src/http/*.ad[bs] \
		${WRKSRC}/src/os-linux/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/util.static

.include <bsd.port.mk>
