# Created by: lukin@okbmei.msk.su
# $FreeBSD$

PORTNAME=	freeze
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/compression/ \
		http://www.rebootking.de/distfiles/ \
		http://ngsoftwareltd.com/freebsd/distfiles/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Compression program - often used in QNX

NO_STAGE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	prog
MAKE_ARGS+=	CFLAGS="${CFLAGS} -I. -DCOMPAT" CC="${CC}"
MAN1=		freeze.1 melt.1 unfreeze.1 fcat.1 statist.1
PLIST_FILES=	bin/fcat bin/freeze bin/melt bin/statist bin/unfreeze
PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
