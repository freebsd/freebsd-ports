# $FreeBSD$

PORTNAME=	opusfile
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/ \
		MOZILLA/opus

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Opus playback library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libopus.so:audio/opus

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
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

CONFIGURE_ARGS+=	--disable-examples
INSTALL_TARGET=	install-strip

post-patch:
	@${GREP} -l '@openssl@' ${WRKSRC}/opusurl.pc.in | \
		${XARGS} ${REINPLACE_CMD} -e 's| @openssl@||'
	@${GREP} -L 'src/ftime.c' ${WRKSRC}/Makefile.am | \
		${XARGS} ${REINPLACE_CMD} -e '/dist_doc_DATA/s/COPYING//' \
		-e '/libopusurl_la_SOURCES/s|= \(src/http\.c\)|= src/ftime.c \1|'
	@${CP} ${FILESDIR}/ftime.c ${WRKSRC}/src/

post-install-DOXYGEN-on:
	@${RM} -f ${WRKDIR}/PLIST.doc ; \
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' \
		>> ${WRKDIR}/PLIST.doc ; \
	(cd ${WRKDIR} ; ${SED} -i -e '/PLIST.doc/ r PLIST.doc' ${TMPPLIST})

.include <bsd.port.mk>
