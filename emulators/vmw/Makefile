# $FreeBSD$

PORTNAME=	vmw
PORTVERSION=	060510
CATEGORIES=	emulators
MASTER_SITES=	http://sites.google.com/site/chitchatvmback/storage/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	VM Back Command Line Tools for VMware

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}/src
USES=		iconv

SBINS=		vmw vmshrink vmftp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README-eucj.TXT README-sjis.TXT README.TXT
.for i in ${SBINS}
PORTDOCS+=	${i}-eucj.txt ${i}-sjis.txt ${i}.txt
.endfor
.endif
.for i in ${SBINS}
PLIST_FILES+=	sbin/${i}
.endfor

do-install:
.for i in ${SBINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
