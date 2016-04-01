# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	c2mdoc
PORTVERSION=	20040302
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	#
DISTFILES=

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Script to generate mdoc(7) markup from C functions

RUN_DEPENDS=	cproto:devel/cproto

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/c2mdoc libexec/c2mdoc.awk

post-extract:
	${SED} -e "s|%%LIBEXECDIR%%|${PREFIX}/libexec|g;" \
		${FILESDIR}/c2mdoc > ${WRKDIR}/c2mdoc

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/c2mdoc.awk ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/c2mdoc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
