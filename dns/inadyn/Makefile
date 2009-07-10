# New ports collection makefile for:   inadyn
# Date created:        9 September 2005
# Whom:                Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	inadyn
PORTVERSION=	1.96.2
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.inatech.eu/inadyn/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	INADYN - Simple DYNAMIC DNS client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_RC_SUBR=	inadyn
USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

MAN8=		inadyn.8
MAN5=		inadyn.conf.5
MANCOMPRESSED=	no

PORTDOCS=	readme.html
PLIST_FILES=	bin/inadyn

NO_INSTALL_MANPAGES=yes

post-extract:
	${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$\(CC\)|g' ${WRKSRC}/makefile
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/man/inadyn.8 ${WRKSRC}/readme.html \
		${WRKSRC}/src/dyndns.h

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
	 ${INSTALL_SCRIPT} ${WRKSRC}/bin/linux/inadyn ${PREFIX}/bin
	 ${INSTALL_SCRIPT} ${WRKSRC}/man/inadyn.8 ${MANPREFIX}/man/man8
	 ${INSTALL_SCRIPT} ${WRKSRC}/man/inadyn.conf.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
