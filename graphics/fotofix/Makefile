# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fotofix
PORTVERSION=	0.01.1.79
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.mcx2.org/ \
		http://prima.eu.org/cgi-bin/cvsweb.cgi/apps/fotofix/fotofix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple image viewer

BROKEN=		No public distfiles

RUN_DEPENDS=	p5-Prima>=1.21:${PORTSDIR}/x11-toolkits/p5-Prima \
		IPA>=1.03:${PORTSDIR}/graphics/IPA

USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	run
NO_BUILD=	yes

SHEBANG_FILES=	fotofix
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
