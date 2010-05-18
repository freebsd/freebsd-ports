# ex:ts=8
# Ports collection makefile for:  svndelta
# Date created:                   Thu Sep 21, 2006
# Whom:                           mich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	svndelta
PORTVERSION=	1.0.6
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.incava.org/pub/svndelta/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Summarizes and manages differences between local files and Subversion

RUN_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion

USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/diff
	${MKDIR} ${DATADIR}/diff/lcs
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/svndelta.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs.rb ${DATADIR}/diff/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/array.rb ${DATADIR}/diff/lcs/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/block.rb ${DATADIR}/diff/lcs/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/callbacks.rb ${DATADIR}/diff/lcs/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/change.rb ${DATADIR}/diff/lcs/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/hunk.rb ${DATADIR}/diff/lcs/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/ldiff.rb ${DATADIR}/diff/lcs/
	${INSTALL_DATA} ${WRKSRC}/share/svndelta/diff/lcs/string.rb ${DATADIR}/diff/lcs/

	${INSTALL_MAN} ${WRKSRC}/svndelta.1 ${PREFIX}/man/man1/

MAN1=		svndelta.1

.include <bsd.port.mk>
