PORTNAME=	rust-mode
DISTVERSION=	1.0.5-58
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g9c26dc1
CATEGORIES=	devel

MAINTAINER=	pat@patmaddox.com
COMMENT=	Emacs major-mode for editing Rust source code
WWW=		https://github.com/rust-lang/

LICENSE=	APACHE20

USES=			emacs
EMACS_NO_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
GH_PROJECT=	rust-mode

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	@${RM} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/rust-mode-tests.el

.include <bsd.port.mk>
