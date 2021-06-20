# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	github-backup-utils
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES=	https://github.com/github/backup-utils/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GitHub Enterprise Backup Utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		git:devel/git \
		rsync:net/rsync

USES=		shebangfix

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

SHEBANG_FILES=	bin/* share/github-backup-utils/*

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/github-backup-utils/backup.config|${PREFIX}/etc/github.backup.config|g' ${WRKSRC}/share/github-backup-utils/ghe-backup-config

do-install:
	(cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin)
	${INSTALL_DATA} ${WRKSRC}/backup.config-example ${STAGEDIR}${PREFIX}/etc/github.backup.config.sample
	(cd ${WRKSRC}/share/github-backup-utils && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
