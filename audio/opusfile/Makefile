PORTNAME=	opusfile
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/ \
		https://ftp.osuosl.org/pub/xiph/releases/opus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Opus playback library
WWW=		https://opus-codec.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libopus.so:audio/opus

USES=		autoreconf libtool pkgconfig ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

PORTDOCS=	AUTHORS README.md

OPTIONS_DEFINE=	DOXYGEN DOCS
OPTIONS_DEFAULT=	# empty

DOXYGEN_CONFIGURE_ENABLE=	doc
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

CONFIGURE_ARGS+=	--disable-examples
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure.ac
pre-patch:
	@${GREP} -l '@openssl@' ${WRKSRC}/opusurl.pc.in | \
		${XARGS} ${REINPLACE_CMD} -e 's| @openssl@||'
.endif

post-install-DOXYGEN-on:
	@${RM} ${WRKDIR}/PLIST.doc ; \
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' \
		>> ${WRKDIR}/PLIST.doc ; \
	(cd ${WRKDIR} ; ${SED} -i -e '/PLIST.doc/ r PLIST.doc' ${TMPPLIST})

.include <bsd.port.post.mk>
