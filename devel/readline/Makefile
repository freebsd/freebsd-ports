# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	readline
PORTVERSION=	6.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cwru.edu/pub/bash/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for editing command lines as they are typed

LICENSE=	GPLv3

OPTIONS_DEFINE=	TERMCAP
OPTIONS_DEFAULT=TERMCAP
TERMCAP_DESC=	Link against libtermcap

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		readline rluserman history
MAN3=		readline.3 history.3

.include <bsd.port.options.mk>

pre-configure:
.if ${PORT_OPTIONS:MTERMCAP}
	${REINPLACE_CMD} "s/SHOBJ_LDFLAGS =/SHOBJ_LDFLAGS = -ltermcap/" ${WRKSRC}/shlib/Makefile.in
.endif

.include <bsd.port.mk>
