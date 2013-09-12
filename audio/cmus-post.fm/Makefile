# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	post.fm
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	cmus-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Last.fm submitter

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable

USES=	shebangfix perl5
USE_BZIP2=	yes
USE_PERL5=	run
SUB_FILES=	pkg-message
NO_BUILD=	yes
PLIST_FILES=	libexec/${PORTNAME} %%EXAMPLESDIR%%/${PORTNAME}.conf
PLIST_DIRS=	%%EXAMPLESDIR%%
SHEBANG_FILES=	${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec/
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${EXAMPLESDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
