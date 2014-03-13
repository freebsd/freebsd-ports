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

USES=		gmake
USE_DOS2UNIX=	*.cpp

PLIST_FILES=	bin/muscle

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muscle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${DISTDIR}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
