# New ports collection makefile for:	QDBM
# Date created:				18 October 2003
# Whom:					Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	qdbm
PORTVERSION=	1.7.5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	Quick Database Manager

GNU_CONFIGURE=	yes
MAKE_ARGS=	RELCFLAGS="${CFLAGS}" \
		MYSHAREDIR="${DOCSDIR}" \
		MYDOCS="spex.html spex-ja.html"
INSTALLS_SHLIB=	yes

MAN3=		cabin.3 cropen.3 curia.3 depot.3 dpopen.3 hovel.3 \
		odeum.3 odopen.3 qdbm.3 relic.3 villa.3 vlopen.3

.include <bsd.port.mk>
