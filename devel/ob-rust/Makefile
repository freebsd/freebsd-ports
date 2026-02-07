PORTNAME=	ob-rust
PORTVERSION=	g20220824
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pat@patmaddox.com
COMMENT=	Org-Babel support for evaluating Rust code
WWW=		https://github.com/micanzhang/ob-rust

LICENSE=	GPLv3+

RUN_DEPENDS=	${PREFIX}/${EMACS_SITE_LISPDIR}/rust-mode.el:devel/rust-mode \
		rust-script:devel/rust-script

USES=			emacs
EMACS_NO_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	micanzhang
GH_PROJECT=	ob-rust
GH_TAGNAME=	be059d2

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/ob-rust.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
