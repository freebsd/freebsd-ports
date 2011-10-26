# Ports collection makefile for:	rubygem-pdfkit
# Date created:				2011-06-16
# Whom:					rpsfa@rit.edu
#
# $FreeBSD$

PORTNAME=	pdfkit
PORTVERSION=	0.5.2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Uses wkhtmltopdf to create PDFs using HTML

RUN_DEPENDS=	wkhtmltopdf:${PORTSDIR}/converters/wkhtmltopdf

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

REINPLACE_ARGS=	-i ''

post-install:
	@${REINPLACE_CMD} -e '/s.date/d' ${PREFIX}/${GEM_SPEC}

.include <bsd.port.mk>
