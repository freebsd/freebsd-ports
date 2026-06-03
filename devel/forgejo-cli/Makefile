PORTNAME=	forgejo-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/forgejo-contrib/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/ \
		LOCAL/jrm:comp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		fj-comp-${DISTVERSIONFULL}${EXTRACT_SUFX}:comp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	CLI client for Forgejo
WWW=		https://codeberg.org/forgejo-contrib/forgejo-cli

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/fj \
		share/bash-completion/completions/fj \
		share/fish/completions/fj.fish \
		share/zsh/site-functions/_fj

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		 ${STAGEDIR}${PREFIX}/share/fish/completions \
		 ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/fj-comp/fj \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKDIR}/fj-comp/fj.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${WRKDIR}/fj-comp/_fj \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
