# Created by: HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
# $FreeBSD$

PORTNAME=	yc.el
PORTVERSION=	5.2.1
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
DISTNAME=	yc-${PORTVERSION}.el
EXTRACT_SUFX=	.gz

MAINTAINER=	t@nakao.org
COMMENT=	Yet another Canna client for Emacs/XEmacs

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> yc.el
NO_WRKSUBDIR=	yes

USE_EMACS=	yes
YC_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/yc

PLIST_FILES=	%%EMACS_VERSION_SITE_LISPDIR%%/yc/yc.el \
		%%EMACS_VERSION_SITE_LISPDIR%%/yc/yc.elc
PLIST_DIRS=	%%EMACS_VERSION_SITE_LISPDIR%%/yc

OPTIONS_DEFINE=	ICANNA
ICANNA_DESC=	Enable icanna support
ICANNA_RUN_DEPENDS=	icanna:${PORTSDIR}/japanese/icanna

do-build:
	@cd ${WRKDIR} && \
	${EMACS_CMD} -batch -f batch-byte-compile yc.el

do-install:
	@${MKDIR} ${STAGEDIR}${YC_LISPDIR}
	@cd ${WRKDIR} && \
	${INSTALL_SCRIPT} yc.el yc.elc ${STAGEDIR}${YC_LISPDIR}

.include <bsd.port.mk>
