# New ports collection makefile for:	ruby-audiofile
# Date created:		20 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	audiofile
PORTVERSION=	0.2.1
CATEGORIES=	audio ruby
MASTER_SITES=	http://ruby-${PORTNAME}.sourceforge.net/download/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CDDB_DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CDDB_DISTNAME=	cddb-0.2
CDDB_WRKSRC=	${WRKDIR}/example

INSTALL_TARGET=	site-install

DOCS=		audiofile.html audiofile.rd

post-patch:
	${RUBY} -i -pe 'gsub %r|/home/jaredj/ruby-lib/cddb\b|, "cddb"' \
		${CDDB_WRKSRC}/wavcddb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/cddb
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${CDDB_WRKSRC}/* ${RUBY_MODEXAMPLESDIR}/cddb/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
