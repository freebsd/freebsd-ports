# New ports collection makefile for:	Ruby/ODBC
# Date created:		17 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	odbc
PORTVERSION=	0.3
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.ch-werner.de/rubyodbc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-cflags="${PTHREAD_CFLAGS}"
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog README doc/odbc.html

post-patch:
	${RUBY} -i -pe '/require \x27mkmf\x27/ and $$_ += "$$libs.sub!(/-lc\\b/, ENV[\x27PTHREAD_LIBS\x27])\n"' \
		${WRKSRC}/${RUBY_EXTCONF}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/test* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
