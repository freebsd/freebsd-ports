# New ports collection makefile for: rust
# Date created: 2012-01-21
# Whom: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	rust
PORTVERSION=	0.2
CATEGORIES=	lang
MASTER_SITES=	http://dl.rust-lang.org/dist/

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language with a focus on memory safety and concurrency

OPTIONS=	CARGO	"Build with package manager" on

ONLY_FOR_ARCHS=	amd64
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	2.6-2.7

MAN1=		rustc.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900044
LIB_DEPENDS+=	unwind.8:${PORTSDIR}/devel/libunwind
CC=		clang
CXX=		clang++
CONFIGURE_ARGS+=	--enable-clang
.else
USE_GCC=	4.6+
.endif

.if !defined(WITHOUT_CARGO)
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl \
		git:${PORTSDIR}/devel/git \
		gpg:${PORTSDIR}/security/gnupg
PLIST_SUB+=	CARGO=""
.else
PLIST_SUB+=	CARGO="@comment "
.endif

LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo

MAKE_ARGS+=		CC=${CC} CXX=${CXX} ARCH=x86_64
CONFIGURE_ARGS+=	--disable-valgrind --disable-docs

post-patch:
	${REINPLACE_CMD} \
	    -e '/probe_need CFG_CURL/d' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} \
	    -e 's|subprocess.call(\["curl"|subprocess.call(["fetch"|' \
	    ${WRKSRC}/src/etc/snapshot.py
	${REINPLACE_CMD} \
	    -e 's|$$(PREFIX_ROOT)/share/man|${MANPREFIX}/man|' \
	    ${WRKSRC}/mk/install.mk
.if defined(WITHOUT_CARGO)
	${REINPLACE_CMD} \
	    -e '/$$(Q)$$(call INSTALL,$$(HB3),$$(PHB),cargo$$(X))/d' \
	    ${WRKSRC}/mk/install.mk
.endif

.include <bsd.port.post.mk>
