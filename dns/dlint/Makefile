# ex:ts=8
# Ports collection makefile for:  dlint
# Version required:     	  1.3.2
# Date created:			  Wed Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	dlint1.3.2
PKGNAME=	dlint-1.3.2
CATEGORIES=	net
MASTER_SITES=	http://www.domtools.com/pub/

MAINTAINER=     obrien@FreeBSD.org

NO_BUILD=	yes
MAN8=		dlint.8

do-configure:
	@${MV} ${WRKSRC}/dlint ${WRKSRC}/dlint.orig
	@${SED} -e 's:/usr/local/bin:${PREFIX}/sbin:g'  \
		${WRKSRC}/dlint.orig >${WRKSRC}/dlint
	@${SED} -e 's:DLINT 1:DLINT 8:g' ${WRKSRC}/dlint.1  >${WRKSRC}/dlint.8

do-install:
	cd ${WRKSRC} ; ${INSTALL_SCRIPT} dlint digparse ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dlint.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dlint
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dlint
.endif

.include <bsd.port.mk>
