# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	p4delta
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Summarizes and manages differences between local files and Perforce

RUN_DEPENDS=	${LOCALBASE}/bin/p4:devel/p4

USE_RUBY=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/p4delta man/man1/p4delta.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/ruby|#!${RUBY}|' ${WRKSRC}/p4delta

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/p4delta.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
