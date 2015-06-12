# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	post.fm
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	cmus-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Last.fm submitter

BROKEN=		No public distfiles

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable

USES=	shebangfix perl5 tar:bzip2
USE_PERL5=	run
SUB_FILES=	pkg-message
NO_BUILD=	yes
PLIST_FILES=	libexec/${PORTNAME} %%EXAMPLESDIR%%/${PORTNAME}.conf
SHEBANG_FILES=	${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
