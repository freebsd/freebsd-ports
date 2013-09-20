# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	inadyn
PORTVERSION=	1.96.2
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://www.inatech.eu/inadyn/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Dynamic DNS update client

USE_RC_SUBR=	inadyn
USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

MAN5=		inadyn.conf.5
MAN8=		inadyn.8

PORTDOCS=	readme.html
PLIST_FILES=	bin/inadyn

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$\(CC\)|g' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/man/inadyn.8 ${WRKSRC}/readme.html \
		${WRKSRC}/src/dyndns.h

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} -p ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/bin/linux/inadyn ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.conf.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
