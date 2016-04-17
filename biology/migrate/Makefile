# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	migrate
PORTVERSION=	3.6.11
CATEGORIES=	biology
MASTER_SITES=	http://popgen.sc.fsu.edu/currentversions/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to estimate population sizes and migration rates

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
EXTRACT_AFTER_ARGS=--exclude zlib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_GMAKE="${MAKE}"
MAKE_ARGS=	PRETTYCFLAGS="${CFLAGS} -DNOJPEG -DNOZLIB -DNOPNG -Iharu \
		-DPRETTY -lstdc++"

PORTDOCS=	HISTORY README README_PARALLEL_GENERAL ${PORTNAME}.html
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES THREAD
THREAD_DESC=		Build with THREAD support
THREAD_ALL_TARGET=	thread

post-patch:
	@${REINPLACE_CMD} -e 's|="-O "|="$$CFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/PRETTY$$/d' ${WRKSRC}/definitions.h
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/haru/makefile.gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-n ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PORTNAME}-n ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${LN} -sf ${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}-n.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/graphics
	${INSTALL_DATA} ${WRKSRC}/../graphics/* ${STAGEDIR}${DOCSDIR}/graphics

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../example/[A-Za-z]* \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
