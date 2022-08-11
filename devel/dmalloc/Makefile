PORTNAME=	dmalloc
DISTVERSION=	5.6.5
CATEGORIES=	devel
MASTER_SITES=	http://dmalloc.com/releases/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Portable debug memory allocation library

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tar:tgz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	"${STAGEDIR}${PREFIX}"
CONFIGURE_ARGS=	--enable-threads --enable-shlib
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_DATA}"

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all heavy
INSTALL_TARGET=	install

CFLAGS+=	-fPIC

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	makeinfo:print/texinfo \
			texi2html:textproc/texi2html
DOCS_INSTALL_TARGET=	installdocs
DOCS_INFO=	dmalloc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dmalloc
	@(cd ${STAGEDIR}${PREFIX}/lib; \
		${STRIP_CMD} libdmalloc.so.1; \
		${LN} -sf libdmalloc.so.1 libdmalloc.so; \
		${STRIP_CMD} libdmallocxx.so.1; \
		${LN} -sf libdmallocxx.so.1 libdmallocxx.so; \
		${STRIP_CMD} libdmallocth.so.1; \
		${LN} -sf libdmallocth.so.1 libdmallocth.so; \
		${STRIP_CMD} libdmallocthcxx.so.1; \
		${LN} -sf libdmallocthcxx.so.1 libdmallocthcxx.so)

.include <bsd.port.mk>
