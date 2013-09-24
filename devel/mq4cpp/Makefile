# Created by: vanilla
# $FreeBSD$

PORTNAME=	mq4cpp
PORTVERSION=	1.16
CATEGORIES=	devel
MASTER_SITES=	http://www.sixtyfourbit.org/Download/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Message Queuing for C++

OPTIONS_DEFINE=	DOCS

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USES=		pathfix pkgconfig
USE_GNOME=	ltverhack
USE_BZIP2=	yes
USE_DOS2UNIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e \
		'/^install-data-am:/ s|install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
