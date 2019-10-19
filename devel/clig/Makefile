# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	clig
PORTVERSION=	1.9.11.1
PORTREVISION=	3
CATEGORIES=	devel tcl
MASTER_SITES=	https://BSDforge.com/projects/source/devel/clig/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Auto-generate an (argc, argv) processor, usage message, and manpage

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING-2.0

USES=		shebangfix tcl tk
SHEBANG_FILES=	tcl/*.tcl
tk_OLD_CMD=	/usr/bin/wish8.0
NO_BUILD=	yes
MAKEFILE=	makefile
MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS}
MAKE_ARGS=	prefix="${PREFIX}" build_root="${STAGEDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/example/.cvsignore
	@${FIND} -d ${WRKSRC} -type d -and -name CVS -exec ${RM} -r {} \;
	@${REINPLACE_CMD} -e 's|/usr/bin/tclsh|${TCLSH}|; \
		s|/doc/|/share/doc/|; \
		s|-$$(VERSION)||;' \
			${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s|tclsh|${TCLSH}|" \
		${WRKSRC}/man/fixman

.include <bsd.port.mk>
