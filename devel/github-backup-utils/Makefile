# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	github-backup-utils
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	zi@FreeBSD.org
COMMENT=	GitHub Enterprise Backup Utilities

RUN_DEPENDS=	git>0:devel/git \
		rsync>0:net/rsync

USE_GITHUB=	yes
GH_ACCOUNT=	github
GH_PROJECT=	backup-utils
SUB_FILES=	pkg-message
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e \
		's|/etc/github-backup-utils/backup.config|${PREFIX}/etc/github.backup.config|g' \
		${WRKSRC}/share/${PORTNAME}/ghe-backup-config

do-install:
	(cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/share/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/backup.config-example \
		${STAGEDIR}${PREFIX}/etc/github.backup.config.sample

.include <bsd.port.mk>
