# New ports collection makefile for:   postgresql-relay
# Date created:        14 February 2003
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	postgresql-relay
PORTVERSION=	1.3.1
CATEGORIES=	databases net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Multiplex multiple PostgreSQL databases to one relay

MAN8=		postgresql-relay.8
PLIST_FILES=	bin/postgresql-relay \
		etc/postgresql-relay.conf-sample \
		etc/rc.d/postgresql-relay.sh

USE_RC_SUBR=	yes
USE_PERL5_BUILD=yes
SUB_FILES=	postgresql-relay.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postgresql-relay ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/postgresql-relay.conf-sample ${PREFIX}/etc/postgresql-relay.conf-sample
	${INSTALL_MAN} ${WRKSRC}/postgresql-relay.8 ${MAN8PREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKDIR}/postgresql-relay.sh ${PREFIX}/etc/rc.d

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
