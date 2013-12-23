# Created by: johs
# $FreeBSD$

PORTNAME=	meta-cvs
PORTVERSION=	1.1.98
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/meta-cvs/downloads/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A more capable version control system than CVS, built around CVS

BROKEN=	loop on install

OPTIONS_DEFINE=	PDFDOC
PDFDOC_DESC=	Build PDF documentation

BUILD_DEPENDS=	clisp:${PORTSDIR}/lang/clisp \
    		lndir:${PORTSDIR}/devel/lndir
RUN_DEPENDS=	clisp:${PORTSDIR}/lang/clisp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mcvs \
		bin/mcvs-debug \
		${DATADIR:C/${PREFIX}\///}/mcvs.mem \
		${DATADIR:C/${PREFIX}\///}/mcvs-debug.mem
PLIST_DIRS=	${DATADIR:C/${PREFIX}\///}

PORTDOCS=	Meta-CVS-PAPER \
		PORTING \
		QUICK-GUIDE \
		SCRIPTING

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDFDOC} && !defined(NOPORTDOCS)
USE_TEX=	latex:build
PORTDOCS+=	meta-cvs.pdf
.endif

post-patch:
	${REINPLACE_CMD} -e '232s|make|${GMAKE}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|type -P|which|g;s|$$(prefix)/lib|${DATADIR}|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|libc.so.6|libc.so|' ${WRKSRC}/code/clisp-ffi.lisp
	${REINPLACE_CMD} -e '12s|latex|pdflatex|' ${WRKSRC}/docs/tex-manual/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.    if !defined(WITHOUT_PDFDOC)
	(cd ${WRKSRC}/docs/tex-manual && ${GMAKE} && \
	    ${CP} ${WRKSRC}/docs/tex-manual/meta-cvs.pdf ${WRKSRC}/docs/misc-text-files)
.    endif
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/misc-text-files/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
