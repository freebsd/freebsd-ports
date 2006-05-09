# New ports collection makefile for:    moscow-ml
# Date created:         2 August 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	moscow_ml
PORTVERSION=	2.01
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.dina.kvl.dk/~sestoft/mosml/
DISTNAME=	mos201src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Moscow ML, a lightweight implementation of Standard ML

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4 \
		gdbm.3:${PORTSDIR}/databases/gdbm

RESTRICTED=	Restrictions on for-profit distribution.

SUB_FILES=	pkg-message
ALL_TARGET=	world MOSMLHOME=$(MOSMLHOME)
INSTALL_TARGET=	install MOSMLHOME=$(MOSMLHOME)
WRKSRC=		${WRKDIR}/mosml/src
USE_PERL5=	yes
MAKE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" DOCSDIR="${DOCSDIR}" \
		LD_RUN_PATH="${PREFIX}/lib/mosml"

PKGMESSAGE=	${WRKDIR}/pkgmessage

post-patch:
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s,-O2,${CFLAGS} -I${LOCALBASE}/include,"
	${FIND} ${WRKDIR}/mosml/examples -name Makefile -o \
		-name Makefile.stub | ${XARGS} ${REINPLACE_CMD} \
		-e "s,^MOSMLHOME=.*,,"
	${FIND} ${WRKDIR}/mosml/examples -name Makefile -o \
		-name Makefile.stub | ${XARGS} ${REINPLACE_CMD} -e \
		"s,^MOSMLTOOLS=.*,MOSMLTOOLS=camlrunm ${PREFIX}/libexec/mosml,"
	${MKDIR} ${WRKDIR}/mosml/examples/ffi
	${LN} -s ${WRKSRC}/dynlibs/crypt ${WRKDIR}/mosml/examples/ffi
	${LN} -s ${WRKSRC}/dynlibs/interface ${WRKDIR}/mosml/examples/ffi
	${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," \
		${WRKSRC}/dynlibs/crypt/Makefile \
		${WRKSRC}/dynlibs/interface/Makefile

post-install:
	${INSTALL_DATA} ${WRKDIR}/mosml/copyrght/copyrght.att ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/copyrght/copyrght.cl ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/copyrght/gpl2 ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/README ${DOCSDIR}
	${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README.FreeBSD
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} "${DOCSDIR}"
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/mosml/tools/Makefile.stub ${EXAMPLESDIR}
	cd ${WRKDIR}/mosml/examples && \
	${TAR} -cf - --dereference \
	   --exclude=\*.orig --exclude=\*.bak --exclude=\*.w32 * | \
	   ${TAR} -xf - -C "${EXAMPLESDIR}"
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} "${EXAMPLESDIR}"
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
