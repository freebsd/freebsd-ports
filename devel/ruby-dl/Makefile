# New ports collection makefile for:	ruby-dl
# Date created:		1 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dl
PORTVERSION=	0.9
CATEGORIES=	devel ruby
MASTER_SITES=	http://kt-www.jaist.ac.jp/~ttate/ftp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

#WRKSRC=		${WRKDIR}/ruby-${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	site-install

DOCS_EN=	Changes README README.html

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CONFIGURE_ARGS+=	--with-asm
.endif

post-extract:
	@${ECHO} "LIB= test" > ${WRKSRC}/test/Makefile
	@${ECHO} "SHLIB_MAJOR= 1" >> ${WRKSRC}/test/Makefile
	@${ECHO} "SHLIB_MINOR= 0" >> ${WRKSRC}/test/Makefile
	@${ECHO} "SRCS= test.c" >> ${WRKSRC}/test/Makefile
	@${ECHO} ".include <bsd.lib.mk>" >> ${WRKSRC}/test/Makefile

post-patch:
	${RUBY} -i -pe "gsub %r|'\.\./dl'|, %q|'dl'|" ${WRKSRC}/test/test.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/h2rb ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/test/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endif

.include <bsd.port.post.mk>
