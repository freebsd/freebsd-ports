PORTNAME=	yc.el
PORTVERSION=	5.2.1
PORTREVISION=	29
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	yc-${PORTVERSION}.el
EXTRACT_SUFX=	.gz

MAINTAINER=	t@nakao.org
COMMENT=	Yet another Canna client for Emacs
WWW=		http://www.ceres.dti.ne.jp/~knak/yc.html

USES=		emacs
EMACS_FLAVORS_EXCLUDE=	devel_full devel_nox # fail to build

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> yc.el
NO_WRKSUBDIR=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/yc/yc.el \
		${EMACS_VERSION_SITE_LISPDIR}/yc/yc.elc

OPTIONS_DEFINE=	ICANNA
ICANNA_DESC=	Enable icanna support
ICANNA_RUN_DEPENDS=	icanna:japanese/icanna

YC_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/yc

do-build:
	@(cd ${WRKSRC} && \
	${EMACS_CMD} -batch -f batch-byte-compile yc.el)

do-install:
	@${MKDIR} ${STAGEDIR}${YC_LISPDIR}
	(cd ${WRKSRC} && \
		${INSTALL_SCRIPT} yc.el yc.elc ${STAGEDIR}${YC_LISPDIR})

.include <bsd.port.mk>
