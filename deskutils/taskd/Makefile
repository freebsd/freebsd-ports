# Created by: gahr
# $FreeBSD$

PORTNAME=	taskd
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-user server for taskwarrior

LICENSE=	MIT

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

USES=		cmake:outsource
CFLAGS+=	-g -O0

PLIST_FILES=	bin/taskd \
		bin/taskdctl \
		man/man1/taskd.1.gz \
		man/man5/taskdrc.5.gz

PORTDOCS=	*

.include <bsd.port.mk>
