# New ports collection makefile for:	QDBM
# Date created:				18 October 2003
# Whom:					Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	qdbm
PORTVERSION=	1.7.32
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://qdbm.sourceforge.net/ \
#		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	Quick Database Manager

USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-zlib
MAKE_ARGS=	RELCFLAGS="${CFLAGS}" \
		MYDATADIR="${DOCSDIR}" MYDOCS="${PORTDOCS}"
INSTALLS_SHLIB=	yes
.if !defined(NOPORTDOCS)
PORTDOCS=	spex.html spex-ja.html ChangeLog NEWS
.endif

MAN3=		cabin.3 curia.3 depot.3 hovel.3 odeum.3 qdbm.3 relic.3 villa.3
MLINKS=		curia.3 cropen.3 depot.3 dpopen.3 \
		odeum.3 odopen.3 villa.3 vlopen.3 villa.3 vista.3

post-build:
	cd ${WRKSRC}/lab; ${MAKE} CC="${CC}" CFLAGS="${CFLAGS}" fmtcnv031127

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lab/fmtcnv031127 ${PREFIX}/bin

.include <bsd.port.mk>
