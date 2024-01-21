PORTNAME=	paexec
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Parallel executor, distributes tasks over network
WWW=		https://sourceforge.net/projects/paexec/

LICENSE=	MIT

BUILD_DEPENDS=	mkcmake:devel/mk-configure \
		runawk:lang/runawk
LIB_DEPENDS=	libmaa.so:devel/libmaa

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		localbase:ldflags perl5
USE_PERL5=	build
MAKE_ENV=	SUBPRJ_DFLT="${SUBPRJ_DFLT}"

SUBPRJ_DFLT=	paexec paargs doc examples
MAKE_ENV+=	EGDIR="${STAGEDIR}${EXAMPLESDIR}" \
			DOCDIR="${STAGEDIR}${DOCSDIR}" \
			BINDIR="${STAGEDIR}${PREFIX}/bin" \
			MANDIR="${STAGEDIR}${PREFIX}/share/man" WARNERR="no"

do-build:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} \
		${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/presentation/${PORTNAME}.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
