# ex:ts=8
# Ports collection makefile for:	ragel
# Date created:			Mar 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ragel
PORTVERSION=	5.23
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.queensu.ca/home/thurston/ragel/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	GPERF="${LOCALBASE}/bin/gperf"

MAN1=		ragel.1 rlgen-cd.1 rlgen-dot.1 rlgen-java.1 rlgen-ruby.1
PLIST_FILES=	bin/ragel bin/rlgen-cd

PORTDOCS=	${PORTNAME}-guide-${PORTVERSION}.pdf

.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTDOCS}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(CFLAGS)|$$(CXXFLAGS)|g ; \
		 s|gperf -L|$$(GPERF) -L|g'

post-build:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		${MAN1}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/ragel ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rlgen-cd/rlgen-cd ${PREFIX}/bin
.for m in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${m} ${MAN1PREFIX}/man/man1
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
