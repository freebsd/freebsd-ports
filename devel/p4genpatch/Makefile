# New ports collection makefile for:	p4genpatch
# Date created:				29 January 2005
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		p4genpatch
PORTVERSION=		1
CATEGORIES=		devel
MASTER_SITES=		#
DISTFILES=

MAINTAINER=		bms@FreeBSD.org
COMMENT=		Helper scripts for generating RCS patches from Perforce

RUN_DEPENDS=		p4:${PORTSDIR}/devel/perforce

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

USE_PERL5=		yes

SCRIPTS=		bin/p4genpatch bin/p4d2p
PLIST_FILES=		${SCRIPTS}

post-patch:
	${MKDIR} ${WRKSRC}
	${CP} -r ${FILESDIR}/bin ${WRKSRC}
.for script in ${SCRIPTS}
	${REINPLACE_CMD} -e 's,^#!/usr/bin/perl,#!${PERL},g' ${WRKSRC}/${script}
.endfor

do-install:
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
