PORTNAME=	psvn
PORTVERSION=	20150720.214200
PORTREVISION=	19
CATEGORIES=	devel elisp
MASTER_SITES=	http://www.xsteve.at/prg/emacs/
DISTNAME=	psvn.el
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subversion interface for Emacs
WWW=		http://www.xsteve.at/prg/emacs/

LICENSE=	GPLv2+

.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	svn:devel/subversion-lts
.else
RUN_DEPENDS=	svn:devel/subversion
.endif

USES=		emacs

CONFLICTS_INSTALL=	psvn-emacs_*

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}/psvn.el
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}/psvn.el

ELISPDIR=	${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/psvn.* ${ELISPDIR}

.include <bsd.port.mk>
