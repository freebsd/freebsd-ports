# New ports collection makefile for:	fpc-base
# Date created:				10 February 2004
# Whom:				John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	fpc-base
PORTVERSION=	1.0.10
CATEGORIES=	lang devel
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Meta package to install all of the Free Pascal base

RUN_DEPENDS=	fp:${PORTSDIR}/editors/fpc-ide \
		${PAKGDIR}/ibase/ibase60.ppu:${PORTSDIR}/databases/fpc-ibase \
		${PAKGDIR}/mysql/mysql.ppu:${PORTSDIR}/databases/fpc-mysql \
		${PAKGDIR}/odbc/odbcsql.ppu:${PORTSDIR}/databases/fpc-odbc \
		${PAKGDIR}/postgres/postgres.ppu:${PORTSDIR}/databases/fpc-postgres \
		${PAKGDIR}/oracle/oraoci.ppu:${PORTSDIR}/databases/fpc-oracle \
		${PAKGDIR}/regexpr/regexpr.ppu:${PORTSDIR}/devel/fpc-regexpr \
		${PAKGDIR}/inet/inet.ppu:${PORTSDIR}/net/fpc-inet \
		${PAKGDIR}/md5/md5.ppu:${PORTSDIR}/security/fpc-md5 \
		${PAKGDIR}/paszlib/paszlib.ppu:${PORTSDIR}/archivers/fpc-paszlib

PAKGDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/freebsd
DOCSDIR=	${LOCALBASE}/share/doc/fpc
EXAMPLESDIR=	${LOCALBASE}/share/examples/fpc

.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	${DOCSDIR}/user.pdf:${PORTSDIR}/lang/fpc-docs \
		${EXAMPLESDIR}/Makefile.fpc:${PORTSDIR}/lang/fpc-demo
.endif

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
