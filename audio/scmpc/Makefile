# Created by: Pavel Motyrev <legioner.r@gmail.com>
# $FreeBSD$

PORTNAME=	scmpc
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/cmende/${PORTNAME}/

MAINTAINER=	legioner.r@gmail.com
COMMENT=	An Audioscrobbler client for MPD

LICENSE=	GPLv2

LIB_DEPENDS=	confuse.0:${PORTSDIR}/devel/libconfuse \
		curl:${PORTSDIR}/ftp/curl

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20

MAN1=		scmpc.1
PLIST_FILES=	bin/scmpc
PORTDOCS=	NEWS README scmpc.conf.example

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
