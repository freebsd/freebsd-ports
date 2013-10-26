# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	pdfkit
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Uses wkhtmltopdf to create PDFs using HTML

RUN_DEPENDS=	wkhtmltopdf:${PORTSDIR}/converters/wkhtmltopdf

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

REINPLACE_ARGS=	-i ''

NO_STAGE=	yes
post-install:
	@${REINPLACE_CMD} -e '/s.date/d' ${PREFIX}/${GEM_SPEC}

.include <bsd.port.mk>
