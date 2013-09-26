# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	clig
PORTVERSION=	1.9.11.1
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	http://wsd.iitb.fhg.de/~geg/clighome/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto-generate an (argc, argv) processor, usage message, and manpage

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USES+=		tcl
MAKEFILE=	makefile
MAKE_ENV+=	NOPORTDOCS=${NOPORTDOCS}
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${RM} ${WRKSRC}/example/.cvsignore
	@${FIND} -d ${WRKSRC} -type d -and -name CVS -exec ${RM} -r {} \;
	@${REINPLACE_CMD} -e 's|prefix =/usr|prefix=${STAGEDIR}${PREFIX}|; \
		s|/usr/bin/tclsh|${TCLSH}|; \
		s|/doc/|/share/doc/|; \
		s|-$$(VERSION)||;' \
			${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s|tclsh|${TCLSH}|" \
		${WRKSRC}/man/fixman

.include <bsd.port.mk>
