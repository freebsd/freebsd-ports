# New ports collection makefile for:    vmw
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	vmw
PORTVERSION=	060510
CATEGORIES=	emulators
MASTER_SITES=	http://chitchat.at.infoseek.co.jp/vmware/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	VM Back Command Line Tools for VMware

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}/src
USE_ICONV=	yes

SBINS=		vmw vmshrink vmftp

.if !defined(NOPORTDOCS)
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
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/sbin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
