# New ports collection makefile for:	fpc-base
# Date created:				10 February 2004
# Whom:				John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	2.2.0
CATEGORIES=	lang
MASTER_SITES=	# empty
PKGNAMEPREFIX=	fpc-
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Meta package to install all of the Free Pascal base

RUN_DEPENDS=	${UNITSDIR}/gdbint/Package.fpc:${PORTSDIR}/devel/fpc-gdbint \
		${UNITSDIR}/graph/Package.fpc:${PORTSDIR}/graphics/fpc-graph \
		${UNITSDIR}/ibase/Package.fpc:${PORTSDIR}/databases/fpc-ibase \
		${UNITSDIR}/libasync/Package.fpc:${PORTSDIR}/net/fpc-libasync \
		${UNITSDIR}/hash/Package.fpc:${PORTSDIR}/security/fpc-hash \
		${UNITSDIR}/mysql/Package.fpc:${PORTSDIR}/databases/fpc-mysql \
		${UNITSDIR}/netdb/Package.fpc:${PORTSDIR}/net/fpc-netdb \
		${UNITSDIR}/odbc/Package.fpc:${PORTSDIR}/databases/fpc-odbc \
		${UNITSDIR}/oracle/Package.fpc:${PORTSDIR}/databases/fpc-oracle \
		${UNITSDIR}/pasjpeg/Package.fpc:${PORTSDIR}/graphics/fpc-pasjpeg \
		${UNITSDIR}/paszlib/Package.fpc:${PORTSDIR}/archivers/fpc-paszlib \
		${UNITSDIR}/pthreads/Package.fpc:${PORTSDIR}/devel/fpc-pthreads \
		${UNITSDIR}/postgres/Package.fpc:${PORTSDIR}/databases/fpc-postgres \
		${UNITSDIR}/regexpr/Package.fpc:${PORTSDIR}/devel/fpc-regexpr \
		${UNITSDIR}/sqlite/Package.fpc:${PORTSDIR}/databases/fpc-sqlite \
		${UNITSDIR}/httpd-1.3/Package.fpc:${PORTSDIR}/www/fpc-httpd

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
BUILDNAME=	${ARCH}-freebsd

.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	${LOCALBASE}/share/doc/fpdocs-${PORTVERSION}/user.pdf:${PORTSDIR}/lang/fpc-docs
.endif

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
