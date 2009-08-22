# ex:ts=8
# Ports collection makefile for:  p4delta
# Date created:                   Wed Apr 16, 2003
# Whom:                           Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	p4delta
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Summarizes and manages differences between local files and Perforce

RUN_DEPENDS=	${LOCALBASE}/bin/p4:${PORTSDIR}/devel/perforce

USE_RUBY=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/ruby|#!${RUBY}|' ${WRKSRC}/p4delta

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/p4delta.1 ${PREFIX}/man/man1/

MAN1=		p4delta.1
PLIST_FILES=	bin/p4delta

.include <bsd.port.mk>
