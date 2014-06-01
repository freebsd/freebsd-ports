# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	muscle
PORTVERSION=	3.6
CATEGORIES=	biology
MASTER_SITES=	http://www.drive5.com/muscle/downloads${PORTVERSION}/
DISTNAME=	${PORTNAME}${PORTVERSION}_src

.if !defined(NOPORTDOCS)
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${EXTRACT_ONLY}
PORTDOCS=	${PORTNAME}.pdf ${PORTNAME}.html
MASTER_SITES+=	http://www.drive5.com/muscle/:docs
.for file in ${PORTDOCS}
DISTFILES+=	${file}:docs
.endfor
.endif

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Multiple Sequence Comparison by Log-Expectation

FETCH_ARGS=	-A

USES=		dos2unix gmake
DOS2UNIX_FILES=	*.cpp

PLIST_FILES=	bin/muscle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muscle ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${DISTDIR}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
