# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	tgif
PORTVERSION=	20010408
PORTREVISION=	12
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2s.biglobe.ne.jp/~Nori/ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}-2
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby extension library to draw Tgif graphics

BROKEN=		Does not compile
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-09-28

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${TGIF_PORT}:build \
		imake:${PORTSDIR}/devel/imake

# NB not USE_IMAKE; this is required for the tgif build but this
# port doesn't use it directly.

USES=		gettext
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

TGIF_PORT=	graphics/tgif

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-x-dir="${LOCALBASE}" \
		--with-ldflags=" `cd ${WRKSRC}/tgif; ${MAKE} -V LDOPTIONS -V LOCAL_LIBRARIES -V LDLIBS -V EXTRA_LOAD_FLAGS | paste -s -`"
INSTALL_TARGET=	site-install

DOCS_EN=	README
DOCS_JA=	ChangeLog.ja	README.ja

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		Does not build on amd64 or ia64 (missing -fPIC)
.endif

post-extract:
	${LN} -sf `cd ${PORTSDIR}/${TGIF_PORT}; ${MAKE} -V WRKSRC` ${WRKSRC}/tgif

post-patch:
	${RUBY} -i -pe 'gsub %r|\.\./|, "tgif/"' ${WRKSRC}/extconf.rb ${WRKSRC}/*.c

post-install:
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/examples/test??.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/test??_ja.rb ${RUBY_MODEXAMPLESDIR}/ja/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.post.mk>
