# Created by: mich@FreeBSD.org
# $FreeBSD$

PORTNAME=	svndelta
PORTVERSION=	1.0.6
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.incava.org/pub/svndelta/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Summarizes and manages differences between local files and Subversion

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
RUN_DEPENDS=	${LOCALBASE}/bin/svn:devel/subversion

USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}/diff/lcs
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/svndelta.rb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs.rb ${STAGEDIR}${DATADIR}/diff/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/*.rb ${STAGEDIR}${DATADIR}/diff/lcs/
	${INSTALL_MAN} ${WRKSRC}/svndelta.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
