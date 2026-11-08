PORTNAME=	shrink-path.el
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1-8
DISTVERSIONSUFFIX=	-gc14882c
CATEGORIES=	editors elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Fish-style path shortening for Emacs Lisp
WWW=		https://gitlab.com/bennya/shrink-path.el

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dash.el>=1.8.0:devel/dash.el \
		f.el>=0.10.0:devel/f.el \
		s.el>=1.6.1:devel/s.el

USES=		emacs
USE_GITLAB=	yes
GL_ACCOUNT=	bennya
GL_TAGNAME=	c14882c8599aec79a6e8ef2d06454254bb3e1e41

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${ELISPDIR}/shrink-path.el
PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/shrink-path*.el \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
