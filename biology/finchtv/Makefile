# ex:ts=8
# New ports collection makefile for:	FinchTV
# Date created:		10 Aug 2004
# Whom:	      		Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	finchtv
PORTVERSION=	1.3.0
CATEGORIES=	biology
MASTER_SITES=	http://www.geospiza.com/finchtv/download/programs/linux/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A chromatogram trace viewer

USE_LINUX?=	yes
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
SUB_FILES=	pkg-message
STRIP=

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/License.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/Help ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/SampleData/ ${EXAMPLESDIR}
	${BRANDELF} -t Linux ${WRKSRC}/finchtv
	${INSTALL_PROGRAM} ${WRKSRC}/finchtv ${PREFIX}/bin

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
