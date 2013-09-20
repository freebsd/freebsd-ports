# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	umix
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced tool for adjusting soundcard mixers, replacement for aumix

GNU_CONFIGURE=	yes
NO_STAGE=	yes

MAN1=		umix.1
PLIST_FILES=	bin/umix

post-patch:
	@${REINPLACE_CMD} -e \
		's|="/etc"|="$${prefix}/etc"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
