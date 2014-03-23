# Created by: Chuck Robey <chuckr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	moscow_ml
PORTVERSION=	2.01
PORTREVISION=	7
CATEGORIES=	lang
MASTER_SITES=	http://www.itu.dk/~sestoft/mosml/
DISTNAME=	mos201src

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Lightweight implementation of Standard ML

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libgdbm.so:${PORTSDIR}/databases/gdbm

RESTRICTED=	Restrictions on for-profit distribution

USES=		perl5
ALL_TARGET=	world
MAKE_ARGS=	MOSMLHOME="${MOSMLHOME}" DOCSDIR="${DOCSDIR}" \
		LD_RUN_PATH="${PREFIX}/lib/mosml"
WRKSRC=		${WRKDIR}/mosml/src

LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

post-patch: .SILENT
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s,-O2,${CFLAGS} -I${LOCALBASE}/include,"
	${FIND} ${WRKDIR}/mosml/examples -name Makefile -o \
		-name Makefile.stub | ${XARGS} ${REINPLACE_CMD} \
		-e "s,^MOSMLHOME=.*,,"
	${FIND} ${WRKDIR}/mosml/examples -name Makefile -o \
		-name Makefile.stub | ${XARGS} ${REINPLACE_CMD} -e \
		"s,^MOSMLTOOLS=.*,MOSMLTOOLS=camlrunm ${PREFIX}/libexec/mosml,"
	@${MKDIR} ${WRKDIR}/mosml/examples/ffi
	${LN} -s ${WRKSRC}/dynlibs/crypt ${WRKDIR}/mosml/examples/ffi
	${LN} -s ${WRKSRC}/dynlibs/interface ${WRKDIR}/mosml/examples/ffi
	${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," \
		${WRKSRC}/dynlibs/crypt/Makefile \
		${WRKSRC}/dynlibs/interface/Makefile
	${REINPLACE_CMD} -e '/ln -s/s|$$(BINDIR)|../../bin|' \
		${WRKSRC}/mosmllib/Makefile
# Fix inner makefiles and configure script to make port jobs (-jX) safe
	${REINPLACE_CMD} -e '2s,^,cd "$$1" || exit 1 ; shift,' \
		${WRKSRC}/config/autoconf
	${REINPLACE_CMD} -E 's,cd( config); sh (autoconf),sh\1/\2\1,' \
		${WRKSRC}/Makefile
	${FIND} ${WRKSRC} -type f -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -E 's|cd (.+); make|$$(MAKE) -C \1|'

post-install:
	${INSTALL_DATA} ${WRKDIR}/mosml/copyrght/copyrght.att \
		${WRKDIR}/mosml/copyrght/copyrght.cl \
		${WRKDIR}/mosml/copyrght/gpl2 \
		${WRKDIR}/mosml/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PKGMESSAGE} ${STAGEDIR}${DOCSDIR}/README.FreeBSD
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/tools/Makefile.stub ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKDIR}/mosml/examples && ${TAR} -cf - --dereference \
		--exclude=\*.orig --exclude=\*.bak --exclude=\*.w32 * | \
		${TAR} -xf - -C "${STAGEDIR}${EXAMPLESDIR}"
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/lib/mosml/header
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mosml/lib*.so

.include <bsd.port.mk>
