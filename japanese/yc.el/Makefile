PORTNAME=	yc.el
PORTVERSION=	5.2.1
PORTREVISION=	30
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
DISTNAME=	yc-${PORTVERSION}.el
EXTRACT_SUFX=	.gz

MAINTAINER=	t@nakao.org
COMMENT=	Yet another Canna client for Emacs
WWW=		http://www.ceres.dti.ne.jp/~knak/yc.html

USES=		emacs

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> yc.el
NO_WRKSUBDIR=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/yc/yc.el

CONFLICTS_INSTALL=	ja-yc.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	ICANNA
ICANNA_DESC=	Enable icanna support
ICANNA_RUN_DEPENDS=	icanna:japanese/icanna

YC_LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/yc

do-install:
	@${MKDIR} ${STAGEDIR}${YC_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${YC_LISPDIR}

.include <bsd.port.mk>
