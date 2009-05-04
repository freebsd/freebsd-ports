# ex:ts=8
# Ports collection makefile for:  dlint
# Date created:			  Wed Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	dlint
PORTVERSION=	1.4.0
CATEGORIES=	dns
MASTER_SITES=	http://www.sfr-fresh.com/unix/misc/dns/
DISTNAME=	dlint${PORTVERSION}

MAINTAINER=	kimelto@gmail.com
COMMENT=	Lint for DNS zones (Domain Name Server zone verification utility)

NO_BUILD=	yes
MAKE_JOBS_SAFE=	yes
MAN8=		dlint.8

do-configure:
	@${REINPLACE_CMD} -e 's:/usr/local/bin:${PREFIX}/sbin:g' ${WRKSRC}/dlint
	@${SED} -e 's:DLINT 1:DLINT 8:g' ${WRKSRC}/dlint.1  >${WRKSRC}/dlint.8

do-install:
	cd ${WRKSRC} ; ${INSTALL_SCRIPT} dlint digparse ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dlint.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
