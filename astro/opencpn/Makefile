# $FreeBSD$

PORTNAME=	opencpn
PORTVERSION=	5.2.4
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	astro geography

MAINTAINER=	ml@netfence.it
COMMENT=	Concise ChartPlotter/Navigator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.gplv2

LIB_DEPENDS=	libportaudio.so:audio/portaudio \
		libcurl.so:ftp/curl \
		libexif.so:graphics/libexif \
		libexpat.so:textproc/expat2 \
		libsndfile.so:audio/libsndfile \
		libtinyxml.so:textproc/tinyxml \
		liblz4.so:archivers/liblz4

USES=		cmake compiler:c++11-lang gettext-tools gl gnome libarchive \
		localbase pkgconfig sqlite xorg
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	${GH_PROJECT}
GH_PROJECT=	OpenCPN
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2 gtk30 pango
INSTALLS_ICONS=	yes
USE_LDCONFIG=	${PREFIX}/lib/opencpn
USE_WX=		3.0+
WX_CONF_ARGS=	absolute
WX_PREMK=	yes
USE_XORG=	ice sm x11 xext

CMAKE_ARGS=	-DOCPN_BUNDLE_GSHHS=CRUDE
CMAKE_ON=	OCPN_BUNDLE_TCDATA OCPN_FORCE_GTK3 # OCPN_USE_CRASHREPORT
CMAKE_OFF=	OCPN_USE_NEWSERIAL

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

DOCS_CMAKE_ON=	-DOCPN_BUNDLE_DOCS:STRING="ON"
DOCS_CMAKE_OFF=	-DOCPN_BUNDLE_DOCS:STRING="OFF"

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
CMAKE_ARGS+=	-DHAVE_MSSE=OFF -DHAVE_MSSE2=OFF -DHAVE_MSSE3=OFF -DHAVE_MAVX2=OFF -DHAVE_MFPU_NEON=OFF
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's,wx-config,${WX_CONFIG},' \
		-e 's,$${PREFIX_PKGDATA}/doc,${DOCSDIR},g' \
		${WRKSRC}/CMakeLists.txt
.if ${ARCH} != amd64 && ${ARCH} != i386
	@${REINPLACE_CMD} -e '/-msse/d' -e '/-mssse3/d' \
		-e '/-mavx2/d' ${WRKSRC}/CMakeLists.txt
.endif

post-install-DOCS-on:
	${CP} -R ${WRKSRC}/Docs/OSENC ${STAGEDIR}${DOCSDIR}/OSENC.docx

.include <bsd.port.post.mk>
