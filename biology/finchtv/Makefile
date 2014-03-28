# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	finchtv
PORTVERSION=	1.3.1
CATEGORIES=	biology
MASTER_SITES=	http://www.geospiza.com/finchtv/download/programs/linux/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A chromatogram trace viewer

BROKEN=		fails to checksum
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-04-18

USE_LINUX?=	yes
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
SUB_FILES=	pkg-message
STRIP=

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
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
