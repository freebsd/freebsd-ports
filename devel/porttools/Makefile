# New ports collection makefile for:	porttools
# Date created:		2003-06-18
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	porttools
PORTVERSION=	0.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@kolobov.com
COMMENT=	Tools for testing and submitting port updates and new ports

RUN_DEPENDS=	portlint:${PORTSDIR}/devel/portlint \
		sudo:${PORTSDIR}/security/sudo

NO_BUILD=	yes

SCRIPTS=	pr-update testport
MAN1=		pr-change.1 pr-new.1 pr-update.1 testport.1
DOCS=		LICENSE NEWS README THANKS TODO

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	${LN} ${PREFIX}/bin/pr-update ${PREFIX}/bin/pr-change
	${LN} ${PREFIX}/bin/pr-update ${PREFIX}/bin/pr-new
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
