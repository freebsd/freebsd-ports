# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msghack
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	gettext-
# Bundled in fedora gettext srpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alter gettext po files in special ways

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '1s|/usr/bin/python|${PYTHON_CMD}|'\
		${WRKSRC}/${PORTNAME}.py

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
