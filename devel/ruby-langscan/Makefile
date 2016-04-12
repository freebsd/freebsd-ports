# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	langscan
PORTVERSION=	1.2.20070115
CATEGORIES=	devel ruby
MASTER_SITES=	LOCAL/tota/${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Program analyzer for source code search engine

LICENSE=	GPLv2

RUN_DEPENDS=	p5-PPI>=0:textproc/p5-PPI
BUILD_DEPENDS=	flex>=2.5.31:textproc/flex

BROKEN_RUBY21=	yes
BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

USES=		perl5
USE_AUTOTOOLS=	aclocal:env automake:env autoconf:env
USE_RUBY=	yes
USE_PERL5=	run
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
HAS_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

PORTDOCS=	ChangeLog NEWS README
DOCSDIR=	${RUBY_MODDOCDIR}

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-fPIC

CFLAGS+=	-I${LOCALBASE}/include/ruby-${RUBY_VER} \
		-I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}
PLIST_SUB+=	RIPPER="@comment "

post-patch:
	${REINPLACE_CMD} "s|\(flex --version\)|${LOCALBASE}/bin/\1|" ${WRKSRC}/autogen.sh
	${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${REINPLACE_CMD} "s|flex|${LOCALBASE}/bin/flex|"

pre-configure:
	cd ${CONFIGURE_WRKSRC}; ${SH} autogen.sh

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/${PORTNAME}/ocaml/camlexer

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
