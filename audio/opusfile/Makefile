# $FreeBSD$

PORTNAME=	opusfile
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/ \
		${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	opus

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Opus playback library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
		libopus.so:${PORTSDIR}/audio/opus

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

PORTDOCS=	AUTHORS README.txt

OPTIONS_DEFINE=	DOXYGEN DOCS
OPTIONS_DEFAULT=	# empty

DOXYGEN_CONFIGURE_ENABLE=	doc
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| @openssl@||' \
		${WRKSRC}/opusfile.pc.in  ${WRKSRC}/opusurl.pc.in
	@${REINPLACE_CMD} -e '/libopusurl_la_SOURCES/s/http.c/& src\/ftime.c/' \
		-e '/dist_doc_DATA/s/COPYING//' \
		${WRKSRC}/Makefile.am
	@${CP} ${FILESDIR}/ftime.c ${WRKSRC}/src/

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	@${RM} -f ${WRKDIR}/PLIST.doc ; \
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' \
		>> ${WRKDIR}/PLIST.doc ; \
	(cd ${WRKDIR} ; ${SED} -i -e '/PLIST.doc/ r PLIST.doc' ${TMPPLIST})
.endif

.include <bsd.port.mk>
