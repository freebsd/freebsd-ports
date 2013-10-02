# Created by: Christopher Elkins <chrise@scardini.com>
# $FreeBSD$

PORTNAME=	scandoc
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ documentation generator

# The foolowing line may be uncommented when/if PR/182572 is committed,
# the file COPYING should be removed from DOCSDIR installation and plist
#LICENSE=	ARTPERL10

USES=		perl5
NO_BUILD=	yes
OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}/images \
		${STAGEDIR}${DATADIR}/templates ${STAGEDIR}${DATADIR}/test
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "COPYING ChangeLog README scandoc.html" \
			${STAGEDIR}${DOCSDIR}/ && \
		${COPYTREE_SHARE} "images templates test" \
			${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
