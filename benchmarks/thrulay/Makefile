# Created by: shalunov
# $FreeBSD$

PORTNAME=	thrulay
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	SF

MAINTAINER=	shalunov@shlang.com
COMMENT=	Network capacity tester

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	thrulayd
SUB_FILES=	thrulayd
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	ChangeLog README thrulay-protocol.txt thrulay-index.html

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '922s,datarootdir,prefix,g' ${WRKSRC}/configure

post-extract:
	@${CP} ${WRKSRC}/doc/*.[ht]* ${WRKSRC}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
