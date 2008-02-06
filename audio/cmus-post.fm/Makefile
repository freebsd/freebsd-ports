# New ports collection makefile for:	cmus-post.fm
# Date created:		8 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	post.fm
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	cmus-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Last.fm submitter

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
SUB_FILES=	pkg-message
NO_BUILD=	yes
PLIST_FILES=	libexec/${PORTNAME} %%EXAMPLESDIR%%/${PORTNAME}.conf
PLIST_DIRS=	%%EXAMPLESDIR%%

post-patch:
	@${REINPLACE_CMD} -e '1s|#!.*|#!${PERL5}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec/
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${EXAMPLESDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
