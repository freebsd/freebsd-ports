# Created by: Chuck Robey <chuckr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	moscow_ml
PORTVERSION=	2.01
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	http://www.itu.dk/~sestoft/mosml/
DISTNAME=	mos201src

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Lightweight implementation of Standard ML

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		gdbm:${PORTSDIR}/databases/gdbm

RESTRICTED=	Restrictions on for-profit distribution

USE_PERL5=	yes	# XXX: shouldn't it be changed to USE_PERL5_BUILD?
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
# Fix inner makefiles and configure script to make port jobs (-jX) safe
	${REINPLACE_CMD} -e '2s,^,cd "$$1" || exit 1 ; shift,' \
		${WRKSRC}/config/autoconf
	${REINPLACE_CMD} -E 's,cd( config); sh (autoconf),sh\1/\2\1,' \
		${WRKSRC}/Makefile
	${FIND} ${WRKSRC} -type f -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -E 's|cd (.+); make|$$(MAKE) -C \1|'

post-install:
	${INSTALL_DATA} ${WRKDIR}/mosml/copyrght/copyrght.att ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/copyrght/copyrght.cl ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/copyrght/gpl2 ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/README ${DOCSDIR}
	${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README.FreeBSD
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} "${DOCSDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/tools/Makefile.stub ${EXAMPLESDIR}
	cd ${WRKDIR}/mosml/examples && ${TAR} -cf - --dereference \
		--exclude=\*.orig --exclude=\*.bak --exclude=\*.w32 * | \
		${TAR} -xf - -C "${EXAMPLESDIR}"
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} "${EXAMPLESDIR}"
	@${FIND} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
