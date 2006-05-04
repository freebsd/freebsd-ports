# New ports collection makefile for:   inadyn
# Date created:        9 September 2005
# Whom:                Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	inadyn
PORTVERSION=	1.96
CATEGORIES=	dns
MASTER_SITES=	http://inadyn.ina-tech.net/
DISTNAME=	inadyn.v1.96
EXTRACT_SUFX=	.zip

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	INADYN - Simple DYNAMIC DNS client

WRKSRC=		${WRKDIR}/inadyn
USE_GCC=	3.4
USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

MAN8=		inadyn.8
MAN5=		inadyn.conf.5
MANCOMPRESSED=	no

PORTDOCS=	readme.html
PLIST_FILES=	bin/inadyn

NO_INSTALL_MANPAGES=yes

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$\(CC\)|g' ${WRKSRC}/makefile

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
	 ${INSTALL_SCRIPT} ${WRKSRC}/bin/linux/inadyn ${PREFIX}/bin
	 ${INSTALL_SCRIPT} ${WRKSRC}/man/inadyn.8 ${MANPREFIX}/man/man8
	 ${INSTALL_SCRIPT} ${WRKSRC}/man/inadyn.conf.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
