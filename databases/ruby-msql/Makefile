# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	msql
PORTVERSION=	0.2.4a
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://dontstopmusic.no-ip.org/ruby/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby API for mSQL

LIB_DEPENDS=	libmsql.so:${PORTSDIR}/databases/msql

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}
CONFIGURE_ARGS=	--with-msql-dir="${LOCALBASE}/share/msql"
INSTALL_TARGET=	site-install

EXAMPLES_EN=	demo/* sample/*
DOCS_EN=	readme.en.txt doc/en/*
DOCS_JA=	readme.ja.txt

NO_STAGE=	yes
post-configure:
	${ECHO_CMD} '#define INST_DIR "${LOCALBASE}"' >> ${WRKSRC}/site.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
