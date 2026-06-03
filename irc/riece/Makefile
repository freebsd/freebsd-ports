PORTNAME=	riece
PORTVERSION=	9.0.0
PORTREVISION=	29
PORTEPOCH=	1
CATEGORIES=	irc elisp
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC client for Emacs
WWW=		https://www.nongnu.org/riece/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs:build gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

CONFLICTS_INSTALL=	riece-emacs_*

NO_ARCH=	yes

INFO=		riece-en riece-ja

OPTIONS_DEFINE=	DOCS

# do-install:
# 	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/riece
# 	${INSTALL_DATA} ${WRKSRC}/lisp/*.el \
# 		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/riece

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS NEWS.ja README README.ja doc/HACKING doc/HACKING.ja
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${FIND} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/riece \
		-name "*.elc" -delete

.include <bsd.port.mk>
