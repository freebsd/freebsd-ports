# New ports collection makefile for: cbrowser
# Date created:		20 April 2000
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	cbrowser
PORTVERSION=	0.8
CATEGORIES=	devel tk83
MASTER_SITES=	http://download.sourceforge.net/cbrowser/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jkoshy

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	Graphical front end for cscope and cscope clones

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_BUILD=	yes

# Private variables
CBDEST=		${PREFIX}/share/cbrowser/
CBFILES=	README builder.tcl calltree.tcl cbrowser ftcllib.tcl \
		hierarchy.tcl tclIndex widget.tcl

do-install:
	${MKDIR} ${PREFIX}/share/cbrowser/
.for file in ${CBFILES}
	${CP} ${WRKSRC}/${file} ${CBDEST}
.endfor
	${LN} -s ${CBDEST}/cbrowser ${PREFIX}/bin/cbrowser

.include <bsd.port.mk>
