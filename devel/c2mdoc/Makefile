# New ports collection makefile for:	c2mdoc
# Date created:		2 March 2004
# Whom:			Bruce M. Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2mdoc
PORTVERSION=	20040302
CATEGORIES=	devel textproc
MASTER_SITES=	#
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script to generate mdoc(7) markup from C functions

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	cproto:${PORTSDIR}/devel/cproto

NOMAN=

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/c2mdoc libexec/c2mdoc.awk

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/c2mdoc.awk ${PREFIX}/libexec
	${CP} ${FILESDIR}/c2mdoc ${WRKDIR}
	${REINPLACE_CMD} -e "s|%%LIBEXECDIR%%|${PREFIX}/libexec|g;" \
		${WRKDIR}/c2mdoc
	${INSTALL_SCRIPT} ${WRKDIR}/c2mdoc ${PREFIX}/bin

.include <bsd.port.mk>
