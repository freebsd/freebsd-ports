# New ports collection makefile for: 	newfile
# Date created:				Thu Jan 30 17:34:12 CET 2003
# Whom:					Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	newfile
PORTVERSION=	1.0.1.b.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flynn@energyhq.homeip.net

BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
BUILD_DEPENDS+=	rdoc:${PORTSDIR}/textproc/ruby-rdoc

USE_RUBY=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
MAN1=		newfile.1
.endif

pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's@SUBDIRS = src doc data doc-src www@SUBDIRS = src data@g' \
	${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
