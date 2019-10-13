# Created by: Alex Samorukov <samm@freebsd.org>
# $FreeBSD$

PORTNAME=	inadyn
PORTVERSION=	1.96.2
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://www.inatech.eu/inadyn/ \
		LOCAL/dhn
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	samm@freebsd.org
COMMENT=	Dynamic DNS update client

USES=		dos2unix gmake zip
USE_RC_SUBR=	inadyn
MAKEFILE=	makefile

PORTDOCS=	readme.html
PLIST_FILES=	bin/inadyn man/man5/inadyn.conf.5.gz man/man8/inadyn.8.gz

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}
	@${RM} ${WRKSRC}/bin/linux/inadyn

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$\(CC\)|g' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/man/inadyn.8 ${WRKSRC}/readme.html \
		${WRKSRC}/src/dyndns.h

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} -p ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/linux/inadyn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
