# New ports collection makefile for:	Ruby/Tgif
# Date created:		6 April 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	20010408
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2s.biglobe.ne.jp/~Nori/ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}-2
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${TGIF_PORT}:build
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes

TGIF_PORT=	graphics/tgif-nls

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-x-dir="${X11BASE}" \
		--with-ldflags=" `cd ${WRKSRC}/tgif && ${MAKE} -V LDOPTIONS -V LOCAL_LIBRARIES -V LDLIBS -V EXTRA_LOAD_FLAGS | paste -s -`"
INSTALL_TARGET=	site-install

DOCS_EN=	README
DOCS_JA=	ChangeLog.ja	README.ja

post-extract:
	${LN} -sf `cd ${PORTSDIR}/${TGIF_PORT} && ${MAKE} -V WRKSRC` ${WRKSRC}/tgif

post-patch:
	${RUBY} -i -pe 'gsub %r|\.\./|, "tgif/"' ${WRKSRC}/extconf.rb ${WRKSRC}/*.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/ja
	${INSTALL_DATA} ${WRKSRC}/examples/test??.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/examples/test??_ja.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/ja/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
