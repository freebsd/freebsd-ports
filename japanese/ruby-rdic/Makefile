# Ports collection makefile for:	Ruby/rdic
# Date created:			3 Aug 2003
# Whom:				Takahiro Morishita <morishita@skywing.org>
#
# $FreeBSD$
#

PORTNAME=	rdic
PORTVERSION=	0.1.2
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.yasgursfarm.us/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	morishita@skywing.org
COMMENT=	A search tool for Eijiro by ruby

RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/mmap.so:${PORTSDIR}/devel/ruby-mmap

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_SHEBANG_FILES=	rdic \
			cnv2alc.rb \
			cnv2jisx0213.rb \
			cnv2rdic.rb
RUBY_RD_FILES=	xselection.rd \
		xselection.rd.jp

USE_XLIB=	yes

INSTALL_TARGET=	site-install

MAKE_ARGS+=	CFLAGS='-I ${X11BASE}/include'

DOCS_EN=	ChangeLog.rdic \
		ChangeLog.xselection \
		README.eliminate \
		README.func \
		README.keymap \
		README.xselection \
		xselection.html \
		${RUBY_RD_FILES:Mxselection.rd}
DOCS_JA=	README.jp \
		xselection.html.ja \
		${RUBY_RD_FILES:Mxselection.rd.jp}

pre-install:
	${CP} ${WRKSRC}/rdic ${PREFIX}/bin/rdic
	${CP} ${WRKSRC}/cnv2alc.rb ${PREFIX}/bin/cnv2alc
	${CP} ${WRKSRC}/cnv2jisx0213.rb ${PREFIX}/bin/cnv2jisx0213
	${CP} ${WRKSRC}/cnv2rdic.rb ${PREFIX}/bin/cnv2rdic

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
