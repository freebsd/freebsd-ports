# New ports collection makefile for: cbrowser
# Date created:		20 April 2000
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	cbrowser
PORTVERSION=	0.6
CATEGORIES=	devel tk82
MASTER_SITES=	http://www.ziplink.net/~felaco/cbrowser/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jkoshy

MAINTAINER=	jkoshy@freebsd.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes

# Private variables
CBDEST=		${PREFIX}/share/cbrowser/
CBFILES=	builder.tcl calltree.tcl cbrowser hierarchy.tcl tclIndex\
		widget.tcl

do-install:
	${MKDIR} ${PREFIX}/share/cbrowser/
.for file in ${CBFILES}
	${CP} ${WRKSRC}/${file} ${CBDEST}
.endfor
	${LN} -s ${CBDEST}/cbrowser ${PREFIX}/bin/cbrowser

.include <bsd.port.mk>
