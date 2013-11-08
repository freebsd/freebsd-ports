# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	audiofile
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	audio ruby
MASTER_SITES=	SF/ruby-${PORTNAME}/ruby-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CDDB_DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby binding to the audiofile library

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile

USE_RUBY=	yes
NO_STAGE=	yes
USE_RUBY_EXTCONF=	yes

CDDB_DISTNAME=	cddb-0.2
CDDB_WRKSRC=	${WRKDIR}/example

INSTALL_TARGET=	site-install
REINPLACE_ARGS=	-i ""

DOCS=		audiofile.rd

post-patch:
	${REINPLACE_CMD} -E -e "s,/home/jaredj/ruby-lib/(cddb),\1,g" \
		${CDDB_WRKSRC}/wavcddb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/cddb
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${CDDB_WRKSRC}/* ${RUBY_MODEXAMPLESDIR}/cddb/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
