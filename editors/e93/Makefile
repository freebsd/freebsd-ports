# New ports collection makefile for:	e93
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $FreeBSD$
#

PORTNAME=	e93
PORTVERSION=	1.3.2
CATEGORIES=	editors tcl82 tk82
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors
DISTNAME=	${PORTNAME}-1.3r2X
EXTRACT_SUFX=	.tgz

MAINTAINER=	jeremy@external.org
COMMENT=	A nifty editor based on Tcl/Tk

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

do-install:
	${MKDIR} ${PREFIX}/share/doc/e93 ${PREFIX}/lib/e93lib/images \
		${PREFIX}/lib/e93lib/highlightschemes \
		${PREFIX}/lib/e93lib/modules \
		${PREFIX}/lib/e93lib/syntaxmaps
	(cd ${WRKSRC}; \
	 ${INSTALL_PROGRAM} e93 ${PREFIX}/bin; \
	 ${INSTALL_SCRIPT} e93r ${PREFIX}/bin; \
	 ${INSTALL_DATA} LICENSE.TXT ${PREFIX}/share/doc/e93; \
	 ${INSTALL_DATA} README.e93 ${PREFIX}/share/doc/e93; \
	 ${INSTALL_DATA} README.regex ${PREFIX}/share/doc/e93; \
	 ${INSTALL_DATA} README.syntaxmaps ${PREFIX}/share/doc/e93; \
	)
	(cd ${WRKSRC}/e93lib; \
	 ${INSTALL_DATA} e93rc.tcl ${PREFIX}/lib/e93lib; \
	 ${INSTALL_DATA} images/about.ppm ${PREFIX}/lib/e93lib/images; \
	 ${INSTALL_DATA} highlightschemes/schemes.tcl ${PREFIX}/lib/e93lib/highlightschemes; \
	 ${INSTALL_DATA} modules/c.tcl ${PREFIX}/lib/e93lib/modules; \
	 ${INSTALL_DATA} syntaxmaps/unknown.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	 ${INSTALL_DATA} syntaxmaps/asm.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	 ${INSTALL_DATA} syntaxmaps/html.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	 ${INSTALL_DATA} syntaxmaps/java.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	 ${INSTALL_DATA} syntaxmaps/tcl.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	 ${INSTALL_DATA} syntaxmaps/vhdl.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	 ${INSTALL_DATA} syntaxmaps/text.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	 ${INSTALL_DATA} syntaxmaps/c.tcl ${PREFIX}/lib/e93lib/syntaxmaps; \
	)

.include <bsd.port.post.mk>
