# ex:ts=8
# Ports collection makefile for:  p4delta
# Date created:                   Wed Apr 16, 2003
# Whom:                           Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	p4delta
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Summarizes and manages differences between local files and Perforce

USE_RUBY=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/ruby|#!${RUBY}|' ${WRKSRC}/p4delta

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/p4delta.1 ${PREFIX}/man/man1/

MAN1=		p4delta.1
PLIST_FILES=	bin/p4delta

.include <bsd.port.mk>
